#lang racket
( define course-list (cons '("Dept" "Number" "Section" "Class Nbr" "Capacity" "Enrollment")
                             '(("CMSC" "201" "1" "1052" 100 30)
                             ("CMSC" "341" "6" "7447" 40 27)
                             ("CMSC" "341" "3" "7443" "40" 29)
                             ("CMSC" "331" "5" "7746" 40 36)
                             ("CMSC" "331" "6" "7747" 40 "40")
                             ("CMSC" "471" "3" "8196" 40 31))
                             
                      )
)

#|
define a function as (open-seats section)
section is a member of course-list
in this function we calculate the available seats by deducting Enrollement from Capacity
and we prepare a string to be printed to the standard output in the following form:
CMSC341 (Section 6) => 13
|#

(define (open-seats section)
  (string-append
    (list-ref section 0)
    (list-ref section 1)
    " (Section "
    (list-ref section 2)
    ")=>"
   )
  )

#|
define a function as (report-open-seats course-list)
In this function we iterate through course-list
for every course record we need to check whether both Enrollment and Capacity are numbers
If both are numbers then we call the function (open-seats ...) on the course record
if any of them is not a number we just ignore the record
and we print the returned string to the standard output
the result for every record should be printed on a new line
|#

(define (report-open-seats list-of-courses)
  (for-each
    (lambda(position)
     
      (if(and(number?(list-ref position 4))(number?(list-ref position 5)))
      (displayln(string-append(open-seats position) " " (number->string (- (list-ref position 4)(list-ref position 5)))))
      (void)
     )
      )
   (cdr list-of-courses)
  )
  )

; leave the following function call intact
(report-open-seats course-list)
