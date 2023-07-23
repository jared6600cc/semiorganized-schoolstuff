/* Program to find the greatest common divisor
          of two nonnegative integer values          */

#include <stdio.h>

int main (void)
{
   int u, v, temp;

   printf ("Please type in two nonnegative integers.\n");
   scanf ("%i%i", &u, &v);


   while ( v != 0 ) {
      temp = u % v;
      printf("%10d", u);
      printf("%10d", v);
      printf("%10d", temp);
      u = v;
      printf("%10d", u);
      v = temp;
      printf("%10d\n", v);
   }

   printf ("Their greatest common divisor is %i\n", u);

   return 0;
}
