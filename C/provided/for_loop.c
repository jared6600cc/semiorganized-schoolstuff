/*
 *
 *
 */


#include <stdio.h>


int main()
{

   int i = 0,
       j = 0,
       sum = 0;
   
   
   
   sum = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10;

   printf("The sum without the for loop is %d\n", sum);

   printf("for loop #1\n");
   for (i = 1; i <= 10; i++) // here i goes from 1 to 10
   {
      printf("i = %d\n", i);
      sum += i;
   }


   printf("The sum using  for loop #1 is %d\n", sum);


   sum = 0;

   printf("for loop #2\n");
   for (i = 1; i <= 10; )
   {
      printf("i = %d\n", i);
      sum += i;
      i++;
   }
   printf("The sum using  for loop #2 is %d\n", sum);

   sum = 0;

   printf("for loop #3\n");
   i = 1;
   for (; ; )
   {
      if (i > 10)
         break;
      printf("i = %d\n", i);
      sum += i;
      i++;
   }
   printf("The sum using  for loop #3 is %d\n", sum);




   sum = 0;

   for (i = 0; i < 5; i++)
      for (j = 1; j <= 10; j++)
         sum += j;


   printf("the sum done 5 times in a double loop is %d\n", sum);


   for (i = 0; i < 5; i++)
   {
      sum = 0; 

      for (j = 1; j <= 10; j++)
         sum += j;

      printf("the sum is %d for i = %d\n", sum, i);
   }


   return 0;
}
