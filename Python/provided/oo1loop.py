#!/usr/bin/python

# python 2.X: no parens on print; python 3.X: print()

class Employee:
   'Common base class for all employees'
   empCount = 0

   def __init__(self, name, salary):
      self.name = name
      self.salary = salary
      Employee.empCount += 1
      self.number = Employee.empCount
   
   def displayCount(self):
     print ("Total Employee %d" % Employee.empCount)

   def displayEmployee(self):
      print ("Name : ", self.name,  ", Salary: ", self.salary,  ", Number: ", self.number)

   def __str__(self):
      return "name: "+ self.name + " salary: " + str(self.salary)+ " Number: " + str(self.number)

emplList = []

for num in range(0,9):
    print(num)
    emplList.append(Employee("Zara"+str(num), 2000+num*100))

for num in range(0,9):
    print(emplList[num])
 
print ("Total Employee %d" % Employee.empCount)

