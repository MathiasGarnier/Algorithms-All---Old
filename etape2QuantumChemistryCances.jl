""" 
    
    -- ÉTAPE 1 --

    Écrire un code en Julia qui calcule les premiers modes propres de l'Hamiltonien 1D et 2π périodique 
                    H_{V₀} = -1/2 d^2 / dx^2 + V₀
    avec V₀ : R → R une fonction 2π périodique et la densité ρ_{V₀}^0 = 2 |φ_{V₀}^0|^2 du fondamental.

"""

using FFTW
using Plots
using LinearAlgebra
using LaTeXStrings

plot()

x_min, x_max = 0, 2 * π
nb_pts = 500 # Nombre de points de la discrétisation

#x_vals = LinRange(x_min, x_max, nb_pts) # Périodicité, le points 1 est le même que le point final
x_vals = LinRange(x_min, x_max, nb_pts+1)[1:end-1]
dx = x_vals[2] - x_vals[1]

# Définition du potentiel
function V₀(x)
    
    return 0 # sin(2 * x) * mod(1/2 * x^3, 2 * π) # mod(x^2, 2 * π)
end
   
# On construit l'hamiltonien H = T + V
#print(round.(V₀_FFT(), digits=3))
V_hatFFT = FFTW.fft(V₀.(x_vals)) / nb_pts

V_hat = zeros(ComplexF64, nb_pts, nb_pts)

for idx_i in 1:nb_pts

    for idx_j in 1:nb_pts

        V_hat[idx_i, idx_j] = V_hatFFT[mod(idx_i - idx_j, nb_pts) + 1] # cf. Levitt équation 36 
    end
end

vals = [0:(nb_pts ÷ 2 - 1); (-nb_pts ÷ 2):-1]       # Chatgpt ce truc (l'opérateur ÷)
T_hat = Diagonal(1 / 2 .* vals.^2)

H = T_hat + V_hat

# Récupérer les valeurs et vecteurs propres en Fourier
eigen_val, eigen_vec = eigen(H)

# Construire le fondamental (depuis le 1er vec propre)
ψ₀_Fourier = eigen_vec[:, 1]
ψ₀ = FFTW.ifft(ψ₀_Fourier) * nb_pts # Retour en réel (au revoir Fourier)

# On obtient donc l'état fondamental
ψ₀ ./= sqrt(sum(abs2, ψ₀) * dx)  # On divise par la norme de ψ₀ (normalisation)
ρ₀ = 2 .* abs.(ψ₀).^2 



#print("\n")
#print(real(eigen_val[1]))
#print("\n")


#plot!(x_vals, real(FFTW.ifft(ψ₀_Fourier) * nb_pts); label=L"\mathfrak{F}^{-1}(\psi_0 Fourier)")
#plot!(x_vals, real(ψ₀ .* conj.(ψ₀)); label=L"|\psi_0|^2")
#plot!(x_vals, ρ₀; label=L"\rho_0")
#plot!(x_vals, V₀.(x_vals); label=L"V_0")

#plot(0:(nb_pts - 1), real.(eigen_val); label="eigenvalues")

#print("Valeur de ρ₀ : ", sum(ρ₀) * (2 * pi) / nb_pts, " (bon, c'est presque 2...)")





# Désormais, on injecte l'état fondamental (méthode de splitting, résolution TDSE)

# Traduction du code http://staff.ustc.edu.cn/~zqj/posts/Numerical_TDSE/#split-operator-techniques

#function init_wavepacket(x)
#
#    p, σ = 5, 0.4
#    x₀ = π
    #amplitude =  1
#    return (1 / (2 * π * σ^2))^(1/4) * exp(- (x - x₀)^2 / (4 * σ^2)) * exp(1im * p * x)
    # Est-ce vraiment un 4 ? Bah semblerait que oui !
    #return amplitude * exp(- (x - x₀)^2 / (2 * σ^2)) 
#end

function fftfreq(n, d=1.0)

    # Equivalent à numpy.fft.fftfreq

    val = 1.0 / (n * d)
    N = floor(Int, (n - 1) / 2) + 1

    return vcat(0:(N-1), (-floor(Int, n / 2)):-1) * val
end

function splitOperator_kinetic(ψ₀, V, L, dt, N=500)

    ngrid = length(V)
    dx = L[1] / ngrid
    fftfreq_kinetic = fftfreq(ngrid, dx)
    coeff_kinetic = (2 * π)^2 .* fftfreq_kinetic.^2
    print(fftfreq_kinetic[1])

    kinetic_step, potential_halfStep = exp.(-1im * dt * coeff_kinetic / 2), exp.(-1im * dt * V / 2)

    Ψₜ = zeros(ComplexF64, ngrid, N)
    Ψₜ[:, 1] = ψ₀   # Condition initiale (t = 0)

    frames = Vector{Vector{Float64}}(undef, N)
    frames[1] = abs.(ψ₀).^2

    for n in 1:(N - 1)

        Ψₜ[:, n + 1] = potential_halfStep .* FFTW.ifft( kinetic_step .* FFTW.fft( potential_halfStep .* Ψₜ[:, n] ) )
        frames[n + 1] = abs.(Ψₜ[:, n + 1]).^2
    end

    return Ψₜ, frames
end

#x_vals = LinRange(x_min, x_max, 1000)
#ψ₀ = #init_wavepacket.(x_vals)
#V = zeros(Float64, size(x_vals))
#V[x_vals .> 4.5] .= 10.0  # mur à droite

#frames = [copy(abs.(ψ₀).^2)]      # Animate

ψ₀_Fourier = eigen_vec[:, 1] + 0.5 * eigen_vec[:, 2]
ψ₀ = FFTW.ifft(ψ₀_Fourier) * nb_pts
ψ₀ ./= sqrt(sum(abs2, ψ₀) * dx)


ψₜ, frames = splitOperator_kinetic(ψ₀, V₀.(x_vals), [x_max - x_min], 1e-2, 2000)

# Animate
anim = @animate for i in 1:length(frames)
    plot(x_vals, frames[i],
        xlabel="x", ylabel="|ψ(x)|²",
        title="t = $(round(i * 1e-3, digits=3))",
        xlim=(0, 2 * π), ylim=(0, 1.2),
        legend=false, color=:black, lw=2, size=(1920, 1080))
end
gif(anim, "anim.gif", fps = 20)
