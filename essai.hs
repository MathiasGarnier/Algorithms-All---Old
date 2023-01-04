-- pour charger le fichier "essai.hs" : dans GHCI (dans le bon répertoire) :
-- :l essai
-- pour le recharger suite à une modification : 
-- :r

maFonction x y = x**y + x * y
nouvelleFonction x y = (maFonction x y) / (maFonction (x + 1) (y + 1))

my'name'is'john = "john"
maFonction2 x = x + 1

myList = [0..10]

summorial x = sum [1..x]
factorial x = product [2..x]

-- "What if we want a list of all numbers between 1 and 20? Sure, we could just type 
--  them all out but obviously that's not a solution for gentlemen who demand excellence 
--  from their programming languages."

chars = ['a'..'z'] ++ [' '] ++ ['A'..'Z'] ++ [' '] ++ ['0'..'9']

ohhhpasbeau = [0.1, 0.2 .. 1]
twotwotwo = [2 * x | x <- [1..10], 2 * x >= 12] 

remainder7 = [x | x <- [50..100], x `mod` 7 == 3]

remainder x y = [z | z <- [0 .. 100], mod z x == y]

boomBangs xs = [ if x < 10 then "BOOM!" else "BANG!" | x <- xs, even x] 

opCertainXY = [(x * y * 2 - 1)**(1/2) | x <- [1..10], y <- [1, 10], x + y >= 10]

rightTriangleFunctionWithConstraint = [[x, y, z] | x <- [1..10],
                                                   y <- [1..10],
                                                   z <- [1..10],
                                                   x**2 + y**2 == z**2,
                                                   x + y + z == 24]

-- comment écrire la spécification des types de la fonction en dessous hmm
-- on compile et fait un :
-- :t rightTriangleInSquareWithConstraint
-- bon.... mhhh
rightTriangleInSquareSquareWithConstraint upper_bound perimeter = 
    [[x, y, z] | x <- [1..upper_bound],
                 y <- [1..upper_bound],
                 z <- [1..upper_bound],
                 x**2 + y**2 == z**2, -- right angle
                 x + y + z == perimeter] -- si on pouvait remplacer "==" par une relation
                                         -- en général, ce serait² parfait putain

-- To be a member of Ord, a type must first have membership in the prestigious 
-- and exclusive Eq club.

z = map factorial [0..10]

-- comment marchent les "cycle" en Haskell ?

factorialD :: Int -> Int
factorialD 0 = 1
factorialD x = x * factorialD (x - 1)
-- et eux l'écrivent : 
factorialE :: (Integral a) => a -> a  
factorialE 0 = 1  
factorialE n = n * factorialE (n - 1)  
-- est-ce que quelque chose change fondamentalement ?

lucky :: (Integral a) => a -> String  
lucky 7 = "LUCKY NUMBER SEVEN!"  
lucky x = "Sorry, you're out of luck, pal!"   

lucky' :: (Integral a) => a -> String
lucky' x = if x == 7 
            then "7 hehe" 
            else "Sorry, you're out of luck, pal!"

-- n!/(k! (n - k)!)
coeff_binom :: Int -> Int -> Int
coeff_binom k n = if n > k && k >= 0
                then div (factorial n) ((factorial k) * (factorial (n - k)))
                else 0

-- j'ai pas encore les boucles (?, avec les récursions si), mais on essaie
-- exp_directe :: (Floating a) => a -> a -> a -> a -- pourquoi ça ne marche pas avec un
                                                -- Integral à la place de Floating ?
-- exp_directe a b n = (a + b)**n

-- binom_newton a b n = sum [(coeff_binom x n) * a**x * b**(n - x) | x <- [0..n]]

pas_binom_newton_recursion :: Int -> Int -> Int -> Int -- ça suffit pour ce que l'on veut là
pas_binom_newton_recursion a b 0 = 1
pas_binom_newton_recursion a b n = (a + b) * (pas_binom_newton_recursion a b (n - 1))  
-- yeahhhh, type :
-- (Eq t, Num t, Num p) => p -> p -> t -> p J'suis pas sûr de comprendre
-- qui est équivalent à (a + b)**n, avec n entier (a et b aussi, mais ça se change plus facilement)
-- on a plus la récurrence si n n'est pas entier

sum' :: (Num a) => [a] -> a  
sum' [] = 0  
sum' (x:xs) = x + sum' xs  

-- pour le projet, pourquoi pas utiliser des alias ? et après, il parcourt tous les éléments de l'ensemble
-- et vérifie si ça marche bien (en fonction des propriétés voulues), ex :
set_a = [0, 1]
-- est_un_element_neutre :: (Eq a, Integral a) => [a] -> a -> Bool
est_un_element_neutre_addition ensemble neutre = 
    if ensemble == [x + neutre | x <- ensemble] 
        then True 
        else False
est_un_element_neutre_multiplication ensemble neutre = 
    if ensemble == [x * neutre | x <- ensemble] 
        then True 
        else False

-- faudra voir si y'a pas de faux positifs et si tout marche bien + si y'a pas moyen de faire mieux autrement
-- https://zestedesavoir.com/tutoriels/885/introduction-a-la-preuve-de-programmes-c-avec-frama-c-et-son-greffon-wp/
-- ça existe pour Haskell ?

-- bien mettre des parenthèses autour de l'opérateur dans l'appel de la fonction, exemple :
-- est_un_element_neutre [0..10] 0 (+)
est_un_element_neutre ensemble neutre relation = 
    if ensemble == [x `relation` neutre | x <- ensemble] 
        then True 
        else False
-- comment faire si l'ensemble est très gros ? voire de cardinal infini ?

fib 0 = 0
fib 1 = 1
fib x = if x >= 2 
            then(fib (x - 1)) + (fib (x - 2))
            else -1

-- oh, je me suis pris un : 
-- <interactive>: getMBlocks: VirtualAlloc MEM_COMMIT failed: Le fichier de pagination est insuffisant pour terminer cette opération.

list = [0..]

-- ce serait dément de réussir à implémenter un système de raisonnement par récurrence héhé (faudrait toute une
-- structure algébrique et compagnie... HISTOIRE DE POUVOIR DEALER AVEC L'INFINI) Ou alors tout repenser ?
-- c'est à dire raisonner sur une sur-couche plus facilement manipulable et précisément faite pour de la récurrence
-- (récurrences forte, faible, diagonale (de Fermat je crois) [...])

decomposition_add x = [[a, b] | a <- [0..x], b <- [0..x], a + b == x]
contrainte_mult tab = [product x | x <- tab]
-- fait à l'arrache, pas sûr du tout d'avoir fait les bonnes choses
res_pb x = maximum (contrainte_mult (decomposition_add x))
gen_res_pb_jusqua_x x = [res_pb solution | solution <- [0..x]]
-- mhhh vérifier si ça marche bien et si c'est bien ça que l'on demande
-- http://oeis.org/search?q=1%2C2%2C4%2C6%2C9%2C12%2C16%2C20%2C25%2C30&language=english&go=Search
-- Maximum product of two integers whose sum is n. - Matthew Vandermast, Mar 04 2003
-- moyen de faire plus compact ? plus propre ? plus rapide ? se documenter sur ces questions, en général
-- limite en + oo du nième terme sur le n + unième terme tend vers un ?
gen_res_pb_carre_parfait x = [res_pb solution | solution <- [0..x], y <- [0..x], res_pb solution == y**2]
-- http://oeis.org/A008794https://jadensadventures.fandom.com/wiki/Astro_Boy hop là

-- https://downloads.haskell.org/~ghc/7.0.3/docs/html/users_guide/rewrite-rules.html
-- https://mail.haskell.org/pipermail/haskell-cafe/2004-May/006192.html
-- https://mail.haskell.org/pipermail/haskell/2004-November/014939.html
-- http://www.cs.columbia.edu/~sedwards/classes/2007/w4115-fall/reports/HCAS.pdf

flip' f x y = f y x
-- ou ce qui est fourni :
flip'' :: (a -> b -> c) -> (b -> a -> c)  
flip'' f = g  
    where g x y = f y x  
-- y'a une différence avec l'utilisation du where ? j'pense pas gné
-- lambda : 
flip''' f = \x y -> f y x


-- It doesn't matter if you do it with the map and filter functions or list comprehensions.
-- vraiment ?

-- sum (takeWhile (<10000) (filter odd (map (^2) [1..])))  
-- sum (takeWhile (<10000) [n^2 | n <- [1..], odd (n^2)]) 

-- import Data.List (nub, sort)
-- pour en emporter que deux parmi toutes les possibilités

-- HOOGLE, so cool

-- {-# LANGUAGE NoImplicitPrelude #-}
-- https://typeclasses.com/ghc/no-implicit-prelude 
-- faire ":t + TAB" une fois le NoImplicitPrelude activé (sans le NoImplicitPrelude
-- il y a 512 possibilités apparement)

-- module Volume ( computeVolumeNDimensional, DAUTRESCHOSES) where
-- computeVolumeNDimensional domaine = intégrer n fois la fonction identité sur le domaine
-- DAUTRESCHOSES x = faire des choses sur x