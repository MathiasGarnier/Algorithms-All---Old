#lang racket

(define (f x)
  (+ 1 x (expt x 2)))
  
(define (g x)
  (expt 2 x))

(display (f 12))
(display "\n")
(display (g 12))