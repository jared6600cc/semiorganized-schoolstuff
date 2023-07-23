/*
 * this program illustrates the difference between ++n and n++
 *
 */

#include <stdio.h>

int main()
{

   int n, m;

   n = 42;
	
   printf("We start off with n = %d\n", n);

   m = n++;//n++; increments the value of n after the expression is evaluated.

   printf("m=n++: n=%d\t\tm=%d\n", n,m);

   m = ++n;//++n; increments the value of n before the expression is evaluated.

   printf("m=++n: n=%d\t\tm=%d\n", n,m);

   printf("n++: n = %d\t\t ", n);
   printf("n++ = %d, \t\t ", n++);
   printf("n = %d\n", n);

   
   printf("++n: n = %d\t\t ", n);
   printf("++n = %d, \t\t ", ++n);
   printf("n = %d\n", n);




   return 0;


}




