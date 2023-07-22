class A:
    def A(self):
        print('A')

class B(A):
    def B(self):
        print('B')

class C(A,B):
    def C(self):
        print('C')

o = C()
o.A()
o.B()
o.C()