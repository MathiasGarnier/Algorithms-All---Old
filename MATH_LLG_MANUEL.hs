lister_suite func seuil = [func x | x <- [0..seuil]]

 -- Exercice 10
recursive_10 0 = 1
recursive_10 n =    recursive_10 (floor (fromIntegral (n `div` 2))) + 
                    recursive_10 (floor (fromIntegral (n `div` 3))) + 
                    recursive_10 (floor (fromIntegral (n `div` 6))) 
-- 1 3 5 7 9 9 15 15 17 19 ...

conj_question_2 x maximum = [x * (n + 1) - recursive_10 n | n <- [1..maximum]]
conj_question_2_decal x maximum = [x * (n + 1) - recursive_10 n | n <- [0..maximum]]

-- y'a pas mal de "fonctions bordel" juste pour voir deux/trois trucs

test_prelim_2_conj_question x maximum = zipWith (-) (conj_question_2 x maximum) (conj_question_2_decal x maximum)
bool_conj_question_2 n maximum = all (>=0) (conj_question_2 n maximum)

sum_test_prelim_2_conj x maximum = sum (test_prelim_2_conj_question x maximum)

test_prelim_conj_question_2 n = n `div` ((recursive_10 (n + 1)) - 1)

-- exercice 34
recursive_34 0 = 0
recursive_34 n = n - recursive_34 (n - 1)

-- lister_suite recursive_34 100
-- résultat : 
-- [0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,13,14,14,15,15,16,16,
--  17,17,18,18,19,19,20,20,21,21,22,22,23,23,24,24,25,25,26,26,27,27,28,28,29,29,30,
--  30,31,31,32,32,33,33,34,34,35,35,36,36,37,37,38,38,39,39,40,40,41,41,42,42,43,
--  43,44,44,45,45,46,46,47,47,48,48,49,49,50,50]
-- c'est bien ce que j'avais calculer à la main, comment trouver une formule close ? gné