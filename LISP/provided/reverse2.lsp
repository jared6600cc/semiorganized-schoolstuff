
(defun reverse(lis)
  (cond
     ((NULL lis) ())
     (t (append2 (reverse (cdr lis)) (cons (car lis) () )))
   )
)

(defun run()
    (set 'l '(a b c d e f g))
    (reverse l)
)


(defun append2 (lis1 lis2)
(cond
  ((null lis1) lis2)
  (t (cons (car lis1)
  (append2 (cdr lis1) lis2))))
)