#include<stdio.h>

void g();

void f()
{
   int x = 5;
}


int main()
{
  // int x = 10;    // comment this
   printf("%d\n",x);
   g();
}

int x = 12;

void g()
{
    printf("%d\n",x); 
}