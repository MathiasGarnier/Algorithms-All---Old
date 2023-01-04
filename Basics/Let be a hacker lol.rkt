#lang racket

(define note_enum (let ([f 17]
                        [s 16]
                        [t 19]
                        [v 20])
  (max f s t v)))

(print note_enum)
