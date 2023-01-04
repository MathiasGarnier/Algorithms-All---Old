#lang racket

(define lst (list "bjr" "hola" "hallo" "buongiorno"))
(define bool (and (member "hallo" lst) (member "bjr" lst)))

(print (not bool))
