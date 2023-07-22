
(DEFUN eqatlist (lis1 lis2)
    (COND 
        ((null lis1)	 (null lis2))
        ((null lis2)	 NIL)
        ((EQUAL (CAR lis1) (car lis2))
            (eqatlist(cdr lis1) (cdr lis2)))
        (T  nil)
    )
)

