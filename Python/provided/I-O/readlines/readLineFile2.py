#!/usr/bin/python

fname = 'hello.txt'

out = open('out.txt','w')

total = 0

with open(fname) as f:
    content = f.readlines()

for number in content:
    total = total + int(number)
    out.write(number)
    print('number = ' + number)
out.write('\n')
out.write(str(total))
out.close()
f.close()



 
