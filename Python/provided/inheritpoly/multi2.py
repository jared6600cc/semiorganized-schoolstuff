class A:
    def m(self):
        print("m of A called")
class C(A):
    def m(self):
        print("m of C called")
class B(A):
    #pass
    def m(self):
        print("m of B called")

class D(C,B):
    pass
x = D()
x.m()