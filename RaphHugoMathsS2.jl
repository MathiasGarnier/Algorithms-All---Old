# TODO 
# * Trouver le minimum (et maximum) de la fonction choisie (pour avoir un intervalle sur y) 
# minimum() fonctionne très bien ! Or notre fonction est un Observable donc compliqué de la manipuler.
# Faut soit la modifier (j'ai pas réussi) soit faut en faire un "clone" du style fPlot et la fonction que le plot utilise
# Mais pour les calculs en interne ou les manipulations on utiliserait "f(n)" qui n'est pas un Observable.
# Bonne réflexion !
# * Ensuite lier interA et interB aux bornes : xs et xlims()
# * Une fois le problème de la fonction réglée -> Accepter une fonction écrite en latex

primVal = 0
lastVal = 6

using GLMakie
using PlotlyJS # To get the function minimum and maximum
fig = Figure()

# ? Inputs
# * Display
interA_tb = Textbox(fig[2, 1], placeholder = "      [a, b]      ") #, validator = Float64, tellwidth = false)
#interB_tb = Textbox(fig[2, 2], placeholder = "b", validator = Float64, tellwidth = false)
interB_funcExpression = Textbox(fig[2, 9:10], placeholder = "      Expression      ") #, validator = String, tellwidth = false)

sl_n = Slider(fig[2, 3:8], range = 0:1:20, startvalue = 1)

# * Observables
interA = Observable("")
#interB = Observable(1.0)
interfuncExpr = Observable("")
slider_val = Observable(sl_n.startvalue)

# * Interactions
on(interA_tb.stored_string) do s
    primVal = 3
    lastVal = 4
    
end
on(interB_funcExpression.stored_string) do s

    return nothing    
end
on(sl_n.value) do s
    slider_val[] = s
    println(slider_val[])
    println(getindex(slider_val[]))
end


menuModeApprox = Menu(fig[3, 1:2], options = ["Mode d'approximation", "Bernstein", "Jackson", "Remez", "Fourier"])
menuError = Menu(fig[3, 3:4], options = ["Afficher l'erreur", "Différence", "MSE"])
menuOption = Menu(fig[3, 9:10], options = ["Options", "Symbolique", "Speed-up numérique", "Speed-up symbolique"])
menuModeApprox.is_open = false
menuError.is_open = false

xs = primVal:0.001:lastVal

# lift c'est pour dire que c'est reactif

function fPlot()
    lifted = @lift($xs .^ 4 * $slider_val[])
    #lifted = @lift(gen_bernstein($xs, $slider_val[], g_1))
    return lifted
end


function g_1(x)
    return x * sin(x)
end
function g_2(x)
    return x^2
end


ax = Axis(fig[1, 1:10])
lines!(ax, xs, g_1.(xs), label="x")
#lines!(ax, xs, g_2.(xs), label="x^2")
lines!(ax, xs, @lift(sum([g_1(k / getindex($slider_val)) .* binomial(getindex($slider_val), k) .* xs .^ k .* (1 .- xs) .^ (getindex($slider_val) - k); for k in 0:getindex($slider_val)])), label="APPROX")

#x= sum([@lift(binomial($slider_val[], k) .* xs .^($slider_val[] - k) .* (1 - xs) .^ k); for k in 0:$slider_val[]])


#l2=lines(fig[1, 1:10], xs, fPlot())

xlims!(primVal, lastVal)
ylims!(-2, 2)

axislegend()

fig
