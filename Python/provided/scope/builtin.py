# Built-in Scope 
from math import pi 
  
pi = 'global pi variable' 
  
def outer(): 
    # pi = 'outer pi variable' 
    def inner(): 
        #pi = 'inner pi variable' 
        print(pi) 
    inner() 
    
outer() 
 
