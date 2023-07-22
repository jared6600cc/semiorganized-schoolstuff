class Shark:

    # Class variables - like static in java
    animal_type = "fish"
    location = "ocean"

    # Constructor method with instance variables name and age
    def __init__(self, name, age):
        self.name = name
        self.age = age

def main():
    # First object, set up instance variables of constructor method
    sammy = Shark("Sammy", 5)

    # Print out instance variable name
    print(sammy.name)

    # Print out class variable location
    print(sammy.location)

    # Second object
    stevie = Shark("Stevie", 8)

    # Print out instance variable name
    print("stevie name: " + stevie.name)
    print("stevie age: " + stevie.age)
    print("sammy name: " + sammy.name)
    print("sammy age: " + str(sammy.age))
    
    # Print out class variable animal_type
    print("stevie animal type: " + stevie.animal_type)
    print("sammy animal type: " + sammy.animal_type)
if __name__ == "__main__":
    main()