student = {'Jim': 12, 'Anna': 14, 'Preet': 10}

def test(student):
    student = {'Sam':20, 'Steve':21}
    print("Inside the function", student)
    return 

test(student)
print("Outside the function:", student)