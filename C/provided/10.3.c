// More on pointers

#include <stdio.h>

int main (void)
{
     int  i1 = 0, i2 = 0;
     int  *p1 = NULL, *p2 = NULL;

     i1 = 5;
     p1 = &i1;
     i2 = *p1 / 2 + 10;
     p2 = p1;
     
     
     *p2 = 10;
     printf("%x %x\n", p1, p2);
     printf("%x %x\n", &p1, &p2);

     
     printf ("i1 = %i, i2 = %i, *p1 = %i, *p2 = %i\n", i1, i2, *p1, *p2);

     return 0;
}


