 #!/usr/bin/python

def loop1():
    for num in range(10,20):  #to iterate between 10 to 20
       print('num = %d' % num)
       for i in range(2,num): #to iterate on the factors of the number
          if num%i == 0:      #to determine the first factor
             j=num/i          #to calculate the second factor
             print ('%d equals %d * %d' % (num,i,j))
             break #to move to the next number, the #first FOR
       else:                  # else part of the loop
          print (num, 'is a prime number')

def loop2(n):
    for num in range(4,n-1):  #to iterate between 10 to 20
        if n%num == 0:      #to determine the first factor
            print (n, ' is composite' )
            return
    print (n, 'is a prime number')

# very odd
for letter in 'Python':     # First Example
   print ('Current Letter :', letter)

# enhanced for loop like Java
fruits = ['banana', 'apple',  'mango']
for fruit in fruits:        # Second Example
   print ('Current fruit :', fruit)

print ("execute loop1()")
loop1()

print ("execute loop2()")
loop2(37)

print ("Good bye!")
