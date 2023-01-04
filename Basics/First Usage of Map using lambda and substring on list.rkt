#lang racket

(map (lambda (i)
  (substring i 2 5)) (list "Buongiorno" "ventuno" "fucking" "butterfly"))
