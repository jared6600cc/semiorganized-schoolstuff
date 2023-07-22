#!/usr/bin/python

def func1(list):
    print ("in func1 before ",list)
    list = [47,11]
    print ("in func1 after ",list)
 
fib = [0,1,1,2,3,5,8]
print('Calling func1')
func1(fib)
print ("after first call ",fib)

def func2(list):
    print ("in func2 before ",list)
    list += [47,11]
    print ("in func2 after ",list)

print('Calling func2')
#func2(fib)
func2(fib[:])  # uncomment for value parameter
print ("after second call ",fib)
