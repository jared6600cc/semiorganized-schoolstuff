#!/usr/bin/python

def fib(n):      # write Fibonacci series up to n
    a, b = 0, 1  # assigns a = 0 and b = 1
    while b < n:
        print(b, end=' ')
        a, b = b, a+b
    print()

def fib2(n):   # return Fibonacci series up to n
    result = []
    a, b = 0, 1
    while b < n:
        result.append(b)
        a, b = b, a+b
    return result

def fib3(n):    # write Fibonacci series up to n
    a = 1 
    b = 1
    while b < n:
        print(b, end=' ')
        tmp = b
        b = a + b
        a = tmp
    print()

def fact(n):
    if n <= 1:
        return 1
    return n * fact(n-1)

print('call fib()')
fib(25)
print('call fib2()')
print(fib2(25))
print('call fib3()')
fib3(25)
print(fact(5))