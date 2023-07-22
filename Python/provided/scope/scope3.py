 #!/usr/bin/python

# Demonstrates
#   - global and local name resolution
#

a_var = 'global value'

def a_func():
    a_var = 'local value'
    a_var2 = 'hello'
    print(a_var, '[ a_var inside a_func() ]')
    print('a_var in global:', 'a_var' in globals())
    print('a_var in local:', 'a_var' in locals())
    print('a_var2 in global:', 'a_var2' in globals())
    print('a_var2 in local:', 'a_var2' in locals())

a_func()

print(a_var, '[ a_var outside a_func() ]')
a_var = 5
print(a_var, '[ a_var2 outside a_func() ]')

