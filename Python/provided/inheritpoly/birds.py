class Bird: 
  def intro(self): 
    print("There are many types of birds.") 
      
  def flight(self): 
    print("Most of the birds can fly but some cannot.") 
    
class sparrow(Bird): 
  def flight(self): 
    print("Sparrows can fly.") 
      
class ostrich(Bird): 
  def intro(self): 
    print("Hi I am an Ostrich.") 

  def flight(self): 
    print("Ostriches cannot fly.") 
      
obj_bird = Bird() 
obj_spr = sparrow() 
obj_ost = ostrich() 
  
obj_bird.intro() 
obj_bird.flight() 
  
obj_spr.intro() 
obj_spr.flight() 
  
obj_ost.intro() 
obj_ost.flight()

birdCollection = []

birdCollection.append(Bird())
birdCollection.append(sparrow())
birdCollection.append(ostrich())

for num in range(0,3):
    birdCollection[num].intro()