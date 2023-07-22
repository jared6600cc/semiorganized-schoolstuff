;; Jared Bumgardner
;; COP4020
;; Project 4
;; 10 April 2023


;;; Main execution ;;;
(defun demo()
  ; read input string file
  (setq inFile (open "theString.txt" :direction :input))
  (setq theString (read inFile))
  (close inFile)
  
  ; set FSA parameters
  (setq numStates 5)
  (setq alphabet '(x y z a))
  (setq startState 0)
  (setq currState startState)
  (setq acceptStates '(1 3))
  (setq transitions '((0 0 x) (0 1 y) (1 2 x) 
					  (2 2 x) (2 3 y) (3 3 x) 
					  (3 4 z) (4 4 x) (4 1 a)))  
  
  ; recursively evaluate string against FSA
  (eval-fsa theString)
  (values) ;suppress redundant console print 
)


;;; Evaluate theString recursively ;;;
(defun eval-fsa(s)
  (setq currChar (car s))
  (cond
    ((null s)	; base case / s empty
	  (report-instring-validity)
	)
	(t 			; s not empty
      ; check if curr char is in alphabet
	  (if(not(member currChar alphabet))
		(exit-abnormal "String contains char not in alphabet")
	  )
	  
	  ; search transitions & update curr state
	  (mapcar 'match-transitions transitions)
	  
	  ; evaluate rest of string
	  (eval-fsa(cdr s))
	)
  )
)


;;; Report to console validity of given string ;;;
(defun report-instring-validity()
  (if(member currState acceptStates)
    (print "Input string is VALID")
	(print "Input string is INVALID")
  )
)


;;; Print error & Exit ;;;
(defun exit-abnormal(message)
  (report-instring-validity)
  (error message)
)


;;; Search transitions & Update current state ;;;
(defun match-transitions(trans)
  (if (and (eq currState (car trans)) (eq currChar (car(cdr(cdr trans)))))
    (setq currState (car (cdr trans)))
  )
)
