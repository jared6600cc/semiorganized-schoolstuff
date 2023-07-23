/* A program to print out all the special C escape sequences  */
/* Michael Ashley / UNSW / 03-Mar-2003                        */

#include <stdio.h>  // for printf definition 

int main (void) {
   printf ("backslash            \\    \\\\  %d\n", '\\');
   printf ("audible alert (bell) BEL  \\a   %d\n" , '\a');
   printf ("backspace            BS   \\b   %d\n" , '\b');
   printf ("horizontal tab       HT   \\t   %d\n" , '\t');
   printf ("newline              LF   \\n  %d\n"  , '\n');
   printf ("vertical tab         VT   \\v  %d\n"  , '\v');
   printf ("formfeed             FF   \\f  %d\n"  , '\f');
   printf ("carriage return      CR   \\r  %d\n"  , '\r');
   printf ("double quote         \"    \\\"  %d\n", '\"');
   printf ("single quote         \'    \\\'  %d\n", '\'');
   printf ("question mark        ?    \\?  %d\n"  , '\?');

   printf("\v");

   printf("Example of tabs:\n");
   printf("%d\t%d\t%d\t\n", 1, 2, 3);
   printf("%d\t%d\t%d\t\n", 10, 20, 30);
   printf("\n\n");

   printf("Exampl of quotes:\n");
   printf("Here's my code.\n");
   printf("Here\'s my code, still!\n");
   printf("Say after me \"Hello world!\"\n");
   
   return 0;
}  
