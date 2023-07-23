/*
 * Name: Dr. Touma
 * Assignment: HW01
 * Date: Jan 12, 2015
 * 
 * Description: This code illustrates the many uses of printf
 *
 * Compile: gcc -o printf_example.x printf_example.c
 *
 * Run: ./printf_example.x
 *
 */

#include <stdio.h> // needed for printf

int main(void)
{
   //
   printf("----------------------------------\n");
   printf("Printing the string 1234567890\n");
   printf("----------------------------------\n");

   printf("1. Print the string:\n");
   printf("1...5....0....5....0....5....0.....5\n");
   printf("[%s]\n\n", "1234567890");

   printf("2. Print the string:\n");
   printf("1...5....0....5....0....5....0.....5\n");
   printf("Printing %20s in a block of 20 characters wide \n", "1234567890");
   printf("Printing %-20s in a block of 20 characters wide\n\n", "1234567890");

   printf("3. Print the string:\n");
   printf("1...5....0....5....0....5....0.....5\n");
   printf("Printing %5s in a block of 5 characters wide\n", "1234567890");
   printf("Printing %-5s in a block of 5 characters wide\n\n", "1234567890");

   printf("4. Print the string:\n");
   printf("1...5....0....5....0....5....0.....5\n");
   printf("Printing %.15s in a block of 15 characters wide\n", "1234567890");
   printf("Printing %-.15s in a block of 15 characters wide\n\n", "1234567890");

   printf("5. Print the string:\n");
   printf("1...5....0....5....0....5....0.....5\n");
   printf("Printing %20.5s in a block of 20 characters wide, printing the 1st 5 characters\n", "1234567890");
   printf("Printing %-20.5s in a block of 20 characters wide, printing the 1st 5 characters\n\n", "1234567890");
   
   return 0;
}
