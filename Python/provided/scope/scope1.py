 #!/usr/bin/python

i = 1

def foo():
    i = 5
    print(i, 'in foo()')

print(i, 'global')

foo()
