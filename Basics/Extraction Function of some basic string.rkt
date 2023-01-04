#lang racket

(define (extraction_function str f_it l_it)
  (substring str f_it l_it))

(define some_basic_string "Hi there, you should beat this fucking butterfly !")

(extraction_function some_basic_string 0 (- (string-length some_basic_string) 6))