#include <stdio.h>

int main (void)
{
     int   count = 10, x;
     int   *int_pointer = NULL;

     int_pointer = &count;
     printf("The value stored at the address %x is %d\n", int_pointer, *int_pointer);
     
     count = count + 10;
     *int_pointer = count + 10;
     x = *int_pointer;

     printf ("count = %i, x = %i, address of count: %x, value at this address: %d\n", 
            count, x, int_pointer, *int_pointer);

     return 0;
}
