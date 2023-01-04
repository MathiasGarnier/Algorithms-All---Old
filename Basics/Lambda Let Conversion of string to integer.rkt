#lang racket

(define (some)
  (let ([a "1"]
        [b "2"]
        [c "654"])
    ((lambda (s x v) (list (string->number s) (string->number x) (string->number v))) a b c)))

(some)
