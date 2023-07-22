(defun sayHello (n)
  (cond ((= n 1) (princ "last hello"))
  (t (princ "hello") 
     (princ n) 
     (sayHello (- n 1)))
  )
)

