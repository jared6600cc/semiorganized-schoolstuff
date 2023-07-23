/* Jared Bumgardner
 * Based on code provided by Prof Touma
 * 
 */


#include <stdio.h>
#include <math.h>

// sorts the values of an array in ascending order
void  sort_a (int  a[], int  n)
{
   int  i, j, temp;

   for ( i = 0;  i < n - 1;  ++i )
      for ( j = i + 1;  j < n;  ++j )
         if ( a[i] > a[j] ) 
         {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
         }
}

// calculates the mean of the elements of an array
float calculate_mean(const int grades[], int n)
{
   int i;
   float sum = 0.0;

   for (i = 0; i < n; i++)
      sum += grades[i];
   
   sum /= n;

   return sum;
}

// calculates the variance of the emelemts of an array
float calculate_variance(const int grades[], int n)
{
   int i;
   float sum = 0.0;
   float mean = calculate_mean(grades, n);


   for (i = 0; i < n; i++)
      sum += grades[i] * grades[i];
   
   sum = sum/n - mean*mean;

   return sum;

}

// calculates the median of the elemets of an arry
float calculate_median(const int grades[], int n)
{
   int i;
   int temp_array[n]; // temp array tp be manipulated
   float median;

   // copy oroginal array to the temp array 
   for (i = 0; i < n; i++)
      temp_array[i] = grades[i];

   sort_a(temp_array, n);

   if (n % 2 == 0)
      median = (temp_array[n/2] + temp_array[n/2-1])/2.0;
   else
      median = temp_array[n/2];

   return median;
}

// finds the maximum value of the elements of an array
int calculate_max(const int grades[], int n)
{
   int max = 0, i;
   for (i = 0; i < n; i++)   
      if (grades[i] >= max)
         max = grades[i];

   return max;

}

// finds the minimum value of the elements of an array
int calculate_min(const int grades[], int n)
{
   int min = 100, i;

   for (i = 0; i < n; i++)
      if (grades[i] <= min)
         min = grades[i];
   
   return min;
}