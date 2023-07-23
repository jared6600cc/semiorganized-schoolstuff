/*
 * name
 * hw
 *
 * desc
 * date
 *
 * how to run
 * how to execut
 */



#include <stdio.h>


int main(void)
{

   double area, width, length;

   printf("Please enter the width of your rectangle: ");
   scanf("%lf", &width);

   printf("Please enter the length of your rectangle: ");
   scanf("%lf", &length);

   area = length * width;

   printf("The area of your rectangle is %f\n", area);

   return 0;
}
