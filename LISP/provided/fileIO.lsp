(defun write()
  (setq fp (open "out.txt" :direction :output))
  (print (add1 5) fp)
  (close fp)
)

(defun add1(n)
  (+ 1 n)
)

(defun read()
  (setq fp (open ".txt" :direction :input))
  (print (add1 5) fp)
  (close fp)
)


