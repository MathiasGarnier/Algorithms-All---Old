#lang racket

(map (lambda (i)
  (andmap string? (list i))) (list "Buongiorno" "ventuno" "fucking" "butterfly"))
