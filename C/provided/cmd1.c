#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
   int i;
   double d;

   printf("you provided %d arguments:\n", argc);

   for (i = 0; i < argc; i++)
      printf("argv[%d] = %s\n", i, argv[i]);

   i = atoi(argv[1]); 
   d = atof(argv[2]);


   printf("i*i = %d\n", i*i);
   printf("d/3 = %lf\n", d/3);



   return 0;
}
