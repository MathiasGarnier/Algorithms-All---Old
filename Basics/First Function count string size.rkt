#lang racket

(define (my_length_counter_function str_input)
  (string-length str_input))

(write (my_length_counter_function "Hi, I'm the fucking butterfly"))