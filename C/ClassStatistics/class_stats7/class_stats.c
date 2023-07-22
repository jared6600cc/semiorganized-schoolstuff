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

// gets the grades of n students for an assignment from the user 
void get_user_input(int grades[], int n)
{
   int i = 0;

   for (i = 0; i < n; i++)
   {
      printf("Please enter the grade for student #%i: ", i+1);
      scanf("%d", &grades[i]);
   }
}

//bins the grades*
int bin_grades(int num_students, const int *grades, int assignment, int grades_scale[11][assignment])
{
	int i;
	int j;
	int total_count;
	
	//bin grades
	for (i = 0; i < num_students; i++)
      {
         if (grades[i] >= 93)
         {
            grades_scale[0][j]++;
            total_count++;
         }
         else if (grades[i]<= 92 && grades[i] >= 90)
         {
            grades_scale[1][j]++;
            total_count++;
         }
         else if (grades[i] <= 89 && grades[i] >= 87)
         {
            grades_scale[2][j]++;
            total_count++;
         }
         else if (grades[i] <= 86 && grades[i] >= 83)
         {
            grades_scale[3][j]++;
            total_count++;
         }
         else if (grades[i] <= 82 && grades[i] >= 80)
         {
            grades_scale[4][j]++;
            total_count++;
         }
         else if (grades[i] <= 79 && grades[i] >= 77)
         {
            grades_scale[5][j]++;
            total_count++;
         }
         else if (grades[i] <= 76 && grades[i] >= 73)
         {
            grades_scale[6][j]++;
            total_count++;
         }
         else if (grades[i] <= 72 && grades[i] >= 70)
         {
            grades_scale[7][j]++;
            total_count++;
         }
         else if (grades[i]<= 69 && grades[i] >= 67)
         {
            grades_scale[8][j]++;
            total_count++;
         }
         else if (grades[i] <= 66 && grades[i] >= 63)
         {
            grades_scale[9][j]++;
            total_count++;
         }
         else
         {
            grades_scale[10][j]++;
            total_count++;
         }
      }
}

//get stats*
void get_stats(const int *grades, int num_elements, int assignment, Statistics *stats) 
{
	//get stats
	  stats[j].mean = calculate_mean(grades, num_students);
      stats[j].variance = calculate_variance(grades, num_students);
      stats[j].median = calculate_median(grades, num_students);
      stats[j].min = calculate_min(grades,num_students);
      stats[j].max = calculate_max(grades, num_students);
      stats[j].num_of_students = num_students;
}

void display_grades_distribution(int num_assignments, const int grades_scale[11][num_assignments], Statistics *stats)
{

   int i;

   printf("\n");
   printf("\n");
   printf("%-25s", "Assignment #:");
   for (i = 0; i < m; i++)
      printf("%-10i", i+1);
   
   printf("\n");
   for (i = 0; i < 25; i++)
      printf("=");
   for (i = 0; i < 10*m; i++)
      printf("=");
   printf("\n");
   printf("\n");
   printf("%-25s", "Mean:");
   for (i = 0; i < m; i++)
      printf("%-10.2f", stats[i].mean);
   printf("\n");

   printf("%-25s", "Median :");
   for (i = 0; i < m; i++)
      printf("%-10.2f", stats[i].median);
   printf("\n");

   printf("%-25s", "Standard Deviation:");
   for (i = 0; i < m; i++)
      printf("%-10.2f", sqrt(stats[i].variance));
   printf("\n");

   printf("%-25s", "Min:");
   for (i = 0; i < m; i++)
      printf("%-10d", stats[i].min);
   printf("\n");

   printf("%-25s", "Max:");
   for (i = 0; i < m; i++)
      printf("%-10d", stats[i].max);
   printf("\n");

   printf("%-25s", "# of Students:");
   for (i = 0; i < m; i++)
      printf("%-10d", stats[i].num_of_students);
   printf("\n");

   for (i = 0; i < 25; i++)
      printf("=");
   for (i = 0; i < 10*m; i++)
      printf("=");
   printf("\n");
   printf("%-15s%-10s", "Scale", "Grade");
   for (i = 0; i < m; i++)
      printf("%-10s", "Count");
   printf("\n");
   for (i = 0; i < 25; i++)
      printf("=");
   for (i = 0; i < 10*m; i++)
      printf("=");
   printf("\n");
   printf("%-15s%-10s", ">= 93", "A");
   for (i = 0; i < m; i++)
      printf("%-10d", grades_scale[0][i]);
   printf("\n");

   printf("%-15s%-10s", "92 - 90", "A-");
   for (i = 0; i < m; i++)
      printf("%-10d", grades_scale[1][i]);
   printf("\n");

   printf("%-15s%-10s", "89 - 87", "B+");
   for (i = 0; i < m; i++)
      printf("%-10d", grades_scale[2][i]);
   printf("\n");
   
   printf("%-15s%-10s", "86 - 83", "B");
   for (i = 0; i < m; i++)
      printf("%-10d", grades_scale[3][i]);
   printf("\n");

   printf("%-15s%-10s", "82 - 80", "B-");
   for (i = 0; i < m; i++)
      printf("%-10d", grades_scale[4][i]);
   printf("\n");

   printf("%-15s%-10s", "79 - 77", "C+");
   for (i = 0; i < m; i++)
      printf("%-10d", grades_scale[5][i]);
   printf("\n");

   printf("%-15s%-10s", "76 - 73", "C");
   for (i = 0; i < m; i++)
      printf("%-10d", grades_scale[6][i]);
   printf("\n");

   printf("%-15s%-10s", "72 - 70", "C-");
   for (i = 0; i < m; i++)
      printf("%-10d", grades_scale[7][i]);
   printf("\n");

   printf("%-15s%-10s", "69 - 67", "D+");
   for (i = 0; i < m; i++)
      printf("%-10d", grades_scale[8][i]);
   printf("\n");

   printf("%-15s%-10s", "66 - 63", "D");
   for (i = 0; i < m; i++)
      printf("%-10d", grades_scale[9][i]);
   printf("\n");

   printf("%-15s%-10s", "< 63", "F");
   for (i = 0; i < m; i++)
      printf("%-10d", grades_scale[10][i]);
   printf("\n");

}
