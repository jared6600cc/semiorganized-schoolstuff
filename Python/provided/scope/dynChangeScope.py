 #!/usr/bin/python

i = 1

def foo():
    global i
    i = 5
    print(i, 'in foo()')

print(i, 'global')

foo()

print(i, 'global')
