/*
 *This is the implementation of the stats header file
*/

#include <math.h>
#include <string.h>
#include <limits.h>
#include "stats.h"

// structure that holds the statistics for an assignment


// sorts the values of an array in ascending order
void  sort_a (int *data, int size)
{
   int  i, j, temp;

   for ( i = 0;  i < size - 1;  ++i )
      for ( j = i + 1;  j < size;  ++j )
         if ( data[i] > data[j] ) 
         {
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
         }
}

// calculates the mean of the elements of an array
float calculate_mean(const int *data, int size)
{
   int i;
   float sum = 0.0;

   for (i = 0; i < size; i++)
      sum += data[i];
   
   sum /= size;

   return sum;
}

// calculates the variance of the emelemts of an array
float calculate_variance(const int *data, int size)
{
   int i;
   float sum = 0.0;
   float mean = calculate_mean(data, size);


   for (i = 0; i < size; i++)
      sum += data[i] * data[i];
   
   sum = sum/size - mean*mean;

   return sum;

}

// calculates the median of the elemets of an arry
float calculate_median(const int *data, int size)
{
   int i;
   int temp_data[size]; // temp array tp be manipulated
   float median;

   // copy oroginal array to the temp array 
   for (i = 0; i < size; i++)
      temp_data[i] = data[i];

   sort_a(temp_data, size);

   if (size % 2 == 0)
      median = (temp_data[size/2] + temp_data[size/2-1])/2.0;
   else
      median = temp_data[size/2];

   return median;
}

// finds the maximum value of the elements of an array
int calculate_max(const int *data, int size)
{
   int max = 0, i;
   for (i = 0; i < size; i++)   
      if (data[i] >= max)
         max = data[i];

   return max;

}


// finds the minimum value of the elements of an array
int calculate_min(const int *data, int size)
{
   int min = 100, i;

   for (i = 0; i < size; i++)
      if (data[i] <= min)
         min = data[i];
   
   return min;
}
