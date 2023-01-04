#lang racket

(define str "Shut up and run a tornado come !")
((lambda (x) (string-replace x "Shut up" "Sh*t up")) str)