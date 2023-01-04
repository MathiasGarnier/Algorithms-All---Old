#lang racket

(require racket/math)

(define (f x)
  (+ 1 x (expt x 2)))
  
(define (g x)
(expt 2 x))

(g ((lambda (x) (cosh (* x pi))) 1))
(expt 2 (cosh (* 1 pi)))
