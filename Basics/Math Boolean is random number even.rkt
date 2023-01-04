#lang racket

(require racket/math)

(define (is_random_even max)
  (define r (random max))
  (write r)
  (if (= (modulo r 2) 0)
      #t
      #f))

(is_random_even 21)