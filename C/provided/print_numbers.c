/*
 * Name: Dr. Touma
 * Assignment: HW01
 * Date: Jan 12, 2015
 * 
 * Description: This code illustrates printing numbers
 *
 * Compile: gcc -o printf_numbers.x printf_numbers.c
 *
 * Run: ./printf_numbers.x
 *
 */

#include <stdio.h> // needed for printf

int main(void)
{

   int a = 5,
       b = 13,
       c = 0x16,
       d = 016;


   float pi = 3.1415926535897932384626433832795,
         pi2 = 3.1415967;

   double pi3 = 3.1415926535897932384626433832795;

   unsigned short e = 12;

   unsigned char f = 3;

   unsigned int g = 499;

   unsigned long int h = 3000;



   // print regulaer integers using %d and %i
   printf("Printing integers with %%d and %%i\n");
   printf("%d\n", a); 
   printf("%i\n", b); 
   
   // print a regular integer of width 10 - 9 will be spaces since iteger takes up 1 space
   printf("%10d\n", a); 
   
   // print a regular integer of width 4 - fill empty space with zeros
   printf("%04i\n", b);
   
   
   
   printf("Hexadecimal: %x\n", c);
   printf("Octal: %o\n", d);
   printf("Unsigned value: %u\n", g);
   printf("integer: %d\n", d); 
   printf("integer: %d\n", c); 
   
   // print long integers
   
   // print float
   printf("pi (%%f): %f\n", pi);
   printf("pi2 (%%f): %f\n", pi2);
   printf("pi (%%3.2f): %3.2f\n", pi);
   printf("pi2 (%%10.10f): %10.10f\n", pi2);
   printf("Printing pi (%%e): %e\n", pi);
   printf("Printing pi (%%E): %E\n", pi);
   printf("Printing pi (%%g): %g\n", pi);
   printf("Printing pi (%%G): %G\n", pi);

   
   // print doubles
   printf("pi3 (%%f): %f\n", pi3);
   printf("pi3 (%%f): %10.10f\n", pi3);


   printf("pi3 (%%d): %d\n", pi3);
   printf("pi (%%d): %d\n", pi);
   printf("pi (%%d): %d\n", (int)pi);




   return 0;
}
