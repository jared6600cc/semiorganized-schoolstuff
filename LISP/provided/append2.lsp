(defun append2 (lis1 lis2)
(cond
  ((null lis1) lis2)
  (t (cons (car lis1)
  (append (cdr lis1) lis2))))
)
