// Program to reverse the digits of a number

#include <stdio.h>

int main (void)
{
   int  number, right_digit;

   printf ("Enter your number.\n");
   scanf ("%i", &number);


   //printf("\n%20s%20s%20s\n", "number", "right_digit", "new_number");
   while ( number != 0 ) {
//      printf("%20d", number);
      right_digit = number % 10;
      printf ("%d", right_digit);
      number /= 10;
  //    printf("%20d\n", number);
   }

   printf ("\n");

   return 0;
}
