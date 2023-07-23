/*
 * Author: Dr. Touma
 *
 * Description: This code displays the limits per data
 * type. Adapted from // http://en.cppreference.com/w/c/types/limits
 * Compile: gcc -o limits.x limits.c
 *
 * Run: ./limits.x
 *
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>
 
int main(void)
{   
   printf("CHAR_BIT   = %d\n", CHAR_BIT);
   printf("MB_LEN_MAX = %d\n", MB_LEN_MAX);
   printf("\n");
                
   printf("CHAR_MIN   = %+d\n", CHAR_MIN);
   printf("CHAR_MAX   = %+d\n", CHAR_MAX);
   printf("SCHAR_MIN  = %+d\n", SCHAR_MIN);
   printf("SCHAR_MAX  = %+d\n", SCHAR_MAX);
   printf("UCHAR_MAX  = %u\n",  UCHAR_MAX);
   printf("\n");
                                        
   printf("SHRT_MIN   = %+d\n", SHRT_MIN);
   printf("SHRT_MAX   = %+d\n", SHRT_MAX);
   printf("USHRT_MAX  = %u\n",  USHRT_MAX);
   printf("\n");
   
   printf("INT_MIN    = %+d\n", INT_MIN);
   printf("INT_MAX    = %+d\n", INT_MAX);
   printf("UINT_MAX   = %u\n",  UINT_MAX);
   printf("\n");
                                                                        
   // Type specifiers
   printf("LONG_MIN   = %+ld\n", LONG_MIN);
   printf("LONG_MAX   = %+ld\n", LONG_MAX);
   printf("ULONG_MAX  = %lu\n",  ULONG_MAX);
   printf("\n");
   
  printf("LLONG_MIN  = %+lld\n", LLONG_MIN);
  printf("LLONG_MAX  = %+lld\n", LLONG_MAX);
  printf("ULLONG_MAX = %llu\n",  ULLONG_MAX);
  printf("\n");

  printf("float = %.10e\n", FLT_MIN);
  printf("LLONG_MAX  = %.10e\n", FLT_MAX);
  printf("ULLONG_MAX = %.10e\n",  DBL_MAX);
  printf("\n");


  printf("float = %.10e\n", FLT_EPSILON);
  printf("float = %.10e\n", DBL_EPSILON);

}
