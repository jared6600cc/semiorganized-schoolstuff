/*
 * this code illustrates the use of assignment operators
 */

#include <stdio.h>
int main(void)
{

   int counter = 10;

   counter = counter + 10;

   printf("counter = %d\n", counter);
   printf("counter = counter + 10: %d\n", counter);

   counter = 10;
   counter += 10;
   printf("counter = %d\n", counter);
   printf("counter += 10: %d\n", counter);


   counter = 10;
   counter = counter - 5;
   printf("counter = %d\n", counter);
   printf("counter = counter - 5: %d\n", counter);


   counter = 10;
   counter -= 5;
   printf("counter = %d\n", counter);
   printf("counter -= 5: %d\n", counter);


   counter = 10;
   counter = counter * 7;
   printf("counter = %d\n", counter);
   printf("counter = counter * 7: %d\n", counter);

   counter = 10;
   counter *= 7;
   printf("counter = %d\n", counter);
   printf("counter *= 7: %d\n", counter);

   counter = 10;
   counter = counter / 5;
   printf("counter = %d\n", counter);
   printf("counter = counter / 5: %d\n", counter);

   counter = 10;
   counter /= 5;
   printf("counter = %d\n", counter);
   printf("counter /= 5: %d\n", counter);

   counter = 10;
   counter /= 2+3;
   printf("counter /= 2 + 3: %d\n", counter);


   // modulus operator
   printf("%d\n", 10 % 7);
   printf("%d\n", 100 % 16);
   printf("%d\n", 12345 % 10);
   printf("%d\n", 12345 / 10);


}
