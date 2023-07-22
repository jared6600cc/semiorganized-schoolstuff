#!/usr/bin/python

# Demonstrates
#   - global, enclosing, and  scopes
#   - nested function definitions leading to enclosing scopes
#

x = 99
def fun(x):
    y = 100
    print(x, y)    
    def bar():
        y = 10
        print(x, y)
    bar()
    print(x, y) 

fun(77)


