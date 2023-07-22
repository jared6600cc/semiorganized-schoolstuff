(defun readWrite()

  (setq fp (open "lispfile.txt" :direction :output))  ; set up file
  (print "hello" fp)                       ; and fill it with stuff
  (print 12.34 fp)
  (princ "'(a b c d)" fp) (terpri fp)  ; TErminalPRIntline
  (princ "; comment" fp) (terpri fp)
  (princ "(c d)" fp )
  (close fp)

  (setq fp (open "lispfile.txt" :direction :input)) ; read the file
  (print (read fp "done"))             ; returns "hello"
  (print (read fp "done"))             ; returns 12.34
  (print (read fp "done"))             ; returns (QUOTE (A B C D))
   ;   note the macro expansion of QUOTE
   ;   note that "; comment" is gone
  (print (read fp "done")) 
  (close fp)
)