#!/usr/bin/python

class Parrot:
    def fly(self):
        print("Parrot flying")

class Airplane:
    def fly(self):
        print("Airplane flying")

class Whale:
    def swim(self):
        print("Whale swimming")

def lift_off(entity):
    entity.fly()

parrot = Parrot()
airplane = Airplane()
whale = Whale()

lift_off(parrot) # prints `Parrot flying`
lift_off(airplane) # prints `Airplane flying`
try:
    lift_off(whale) # Throws the error `'Whale' object has no attribute 'fly'`
except Exception:
    print("->Whales do not fly!")
lift_off(airplane) # prints `Airplane flying`
print("Got this far")
