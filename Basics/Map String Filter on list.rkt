#lang racket

(map (lambda (i)
  (filter string? (list i))) (list "Buongiorno" "ventuno" "fucking" "butterfly" 54 54 54))
