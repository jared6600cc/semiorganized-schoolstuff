/* This program computes the size of variable using sizeof operator.*/

#include <stdio.h>
int main(){
   int a;
   float b;
   double c;
   char d;
   long e;
   short f;
   long long int g;

   printf("Size of int: %d bytes\n",sizeof(a));
   printf("Size of float: %d bytes\n",sizeof(b));
   printf("Size of double: %d bytes\n",sizeof(c));
   printf("Size of char: %d byte\n",sizeof(d));
   printf("Size of long: %d byte\n",sizeof(e));
   printf("Size of short: %d byte\n",sizeof(f));
   printf("Size of long long int: %d byte\n",sizeof(g));

   return 0;
}
