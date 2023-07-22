pi = 'global pi variable'
  
def outer(): 
    pi = 'outer pi variable'
    print(pi)

    
def inner(): 
    pi = 'inner pi variable' 
    #print(pi)
    #nonlocal pi
    print(pi)  
   
  
outer() 
#inner()
print(pi) 