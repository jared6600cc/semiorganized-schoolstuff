
(defun readWrite()
  (writeF)
  (readF)
)


(defun writeF()
  (setq fp (open "out.txt" :direction :output))
  (print (add1 5) fp)
  (princ "done writing file")
  (princ "\n")
  (close fp)
)

(defun add1(n)
  (+ 1 n)
)

(defun readF()
  (princ "reading file")
  (princ "\n")
  (setq fp (open "out.txt" :direction :input))
  (print (read fp "done"))
  (close fp)
)


