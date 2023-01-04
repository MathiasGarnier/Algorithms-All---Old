#lang racket

(define (inverse_boolean bool)
  (if (equal? bool #t)
      #f
      #t))

(inverse_boolean (equal? (implies #f (= (/ 10 5) 2)) #f))