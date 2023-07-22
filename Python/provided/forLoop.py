#!/usr/bin/python

# a for loop
for num in range(10,20):  #to iterate between 10 to 20
   for i in range(2,num): #to iterate on the factors of the number
      if num%i == 0:      #to determine the first factor
         j=num/i          #to calculate the second factor
         print ('%d equals %d * %d' % (num,i,j))
         break #to move to the next number, the #first FOR
   else:                  # else part of the loop
      print (num, 'is a prime number')

# very odd
for letter in 'Python':     # First Example
   print ('Current Letter :', letter)

# enhanced for loop like Java
fruits = ['banana', 'apple',  'mango']
for fruit in fruits:        # Second Example
   print ('Current fruit :', fruit)

print ("Good bye!")
