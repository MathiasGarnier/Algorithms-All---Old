#lang racket

(define (switch_alternative_also_called_a_cond str)
  (cond
    [(string-contains? str "butterfly")
     "Fuck, the fucking butterfly. We can't kill it now, we're too weak !"]
    [(>= (string-length str) 42)
     "Shut up, let me think, I try to found a solution to kill the fucking butterfly"]
    [else "Hmmm, I don't understand"]))

(define butterfly "Ohhhh, I would kill the butterfly")
(define shut_up "Blablablablablablablablablablablablablablablablablablablablablablabla")
(define other "2 + 3 = -1")

(switch_alternative_also_called_a_cond butterfly)
(switch_alternative_also_called_a_cond shut_up)
(switch_alternative_also_called_a_cond other)
