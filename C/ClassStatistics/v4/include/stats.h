#ifndef STATS
#define STATS

// this is stats.h


// sorts the values of an array in ascending order
void sort_a (int *data , int size) ;

// calculates the mean of the elements of an array
float calculate_mean (const int *data, int size);

// calculates the variance of the emelemts of an array
float calculate_variance (const int *data , int size);

// calculates the median of the elemets of an array
float calculate_median (const int *data , int size );

// finds the maximum value of the elements of an array
int calculate_max ( const int *data , int size);

// finds the minimum value of the elements of an array
int calculate_min ( const int *data , int ize);


#endif
