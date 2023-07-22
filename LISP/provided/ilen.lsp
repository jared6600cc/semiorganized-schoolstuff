(defun test()
  (set 'l '(a s d f g h j l o i u y t))
)

(defun itlen (lst)
        (PROG (sum)
	(setq sum 0)
     again
	(cond 
            ((null lst) (return sum))
         )
	(setq sum (+ 1 sum))
        (setq lst (cdr lst))
     (go again)
))


(defun rec_length (lst)
	(cond
		((null lst) 0)
		(t (+ 1 (rec_length (cdr lst))))
	)
)


