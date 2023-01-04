#lang racket

(define (start_session username password)

  (define (allsgood? usr pass)
    (if (and (non-empty-string? usr) (non-empty-string? pass)
             (equal? usr "default") (equal? pass "root"))
        #t
        #f))
  (cond
    [(allsgood? username password)
     (print "Starting the session... (fake bouuuh)")
     ]
    [else
     (print "Error with username or password.")]))
 
(start_session "default" "root")
