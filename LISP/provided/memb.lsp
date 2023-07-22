
(defun setList()
  (setq l '(a s d f g))
)


(DEFUN MEMB (X L)
    (COND ((NULL L)	 NIL)
        ((ATOM L)	 NIL)
        ((EQUAL X (CAR L)) T)
        (T  (MEMB X (CDR L)))
    )
)

(defun callonlist()
  (setlist)
  (memb 'd l)
)

(defun callnotonlist()
  (setlist)
  (memb 'x l)
)