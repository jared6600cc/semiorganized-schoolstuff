#include <stdio.h>


#define X 20

int x =  10;


void func1(void)
{
   printf("this is the global x in func1. x = %d\n", x);

   // change x
   x = 20;

}

void func2(void)
{
   printf("this is the global x in func2. x = %d\n", x);

   // change x
   x = 30;
}

void func3(void)
{
   int x = 40;
   printf("this is the local x in func3. x = %d\n", x);

}


void func4(int x)
{
   printf("this x was passed into func4. x = %d\n", x);

}

void func5(void)
{
   int x = 500;

   printf("This x is automatic, it gets created when func5 is called and ");
   printf("it dies when func5 returns. x = %d\n", x);

   x = 600;

}

void func6(void)
{
   static int x = 200;
   printf("this x is static; it gets created when func6 is called and it ");
   printf("holds on to its value when func6 returns. x = %d\n", x);

   x += 10;
}

int main()
{
   int x = 100;

   printf("this x belongs to main. x = %d\n", x);

   func1();
   func2();
   func3();
   func4(4000);
   func5();
   func5();
   func5();
   func5();
   func6();
   func6();
   func6();
   func6();
   func5();
   func3();
   func1();
   func6();
   printf("X = %d\n", X);
   return 0;
}
