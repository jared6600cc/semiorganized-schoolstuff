/*
 * Jared Bumgardner
 * based on code by Jimmy Touma
 * HM04
 *
 * gcc input.c -lm
 */


#include <stdio.h>
#include <math.h>

void sort_array(int grades[], int n) {
	//declare variables
	int temp;
	int i;
	int k;
	
	//sort the array
	for (i = 0; i < n; i++) {
		for (k = i + 1; k < n; k++) {
			if (grades[i] > grades[k]) {
				temp = grades[i];
				grades[i] = grades[k];
				grades[k] = temp;
			}
		}
	}
}

float calculate_mean(int grades[], int n) {
	
	int i;
	float mean;
	float sum = 0;
	
	//calculate the sum
	for (i = 0; i < n; i++) {
		sum = sum + grades[i];
	}
	
	//caluclate the mean
	mean = sum / n;

	return mean;
}

float calculate_variance(int grades[], int n) {
	//declare variables
	int i;
	int j;
	int sum2 = 0;
	float mean;
	float variance;
	
	//calculate needed variables
	for (i = 0; i < n; i++) {
		sum2 += grades[i] * grades[i];
	}
	
	mean = calculate_mean(grades, n);
	
	//calculate variance
	variance = (float) sum2/n - mean * mean;

}

float calculate_median(int grades[], int n) {
	//declare variables
	float remainder = n % 2;
	float median;
	
	//sort array
//	sort_array(grades, n);
	
	//calculate median
	if (remainder = 0) {
		//find median for even # of elements
		median = grades[(n / 2) - 1];
	}
	else {
		//find median for odd # of elements
		median = grades[((n / 2) % 1) - 1];
	}
	
	return median;
}

int main(void)
{
   int n;
   int i = 0;

   printf("How many grades students are in the class?  ");
   scanf("%d", &n);

   int grades[n];

   for (i = 0; n < n; i++)
      grades[i] = 0;
   

   int sum = 0,
       sum2 = 0,
       max = 0,
       min = 100;
   
   int total_count = 0;
   int grades_scale[11] = {0};
   
   float mean = 0,
         variance = 0;

   
   for (i = 0; i < n; i++)
   {
      printf("Please enter a grade between 0 and 100 for student # %i: ", i+1);
      scanf("%d", &grades[i]);
      sum += grades[i];
      sum2 += grades[i] * grades[i];
      
      if (grades[i] >= max)
         max = grades[i];

      if (grades[i] <= min)
         min = grades[i];

      if (grades[i] >= 93)
      {
         grades_scale[0]++;
         total_count++;
      }
      else if (grades[i]<= 92 && grades[i] >= 90)
      {
         grades_scale[1]++;
         total_count++;
      }
      else if (grades[i] <= 89 && grades[i] >= 87)
      {
         grades_scale[2]++;
         total_count++;
      }
      else if (grades[i] <= 86 && grades[i] >= 83)
      {
         grades_scale[3]++;
         total_count++;
      }
      else if (grades[i] <= 82 && grades[i] >= 80)
      {
         grades_scale[4]++;
         total_count++;
      }
      else if (grades[i] <= 79 && grades[i] >= 77)
      {
         grades_scale[5]++;
         total_count++;
      }
      else if (grades[i] <= 76 && grades[i] >= 73)
      {
         grades_scale[6]++;
         total_count++;
      }
      else if (grades[i] <= 72 && grades[i] >= 70)
      {
         grades_scale[7]++;
         total_count++;
      }
      else if (grades[i]<= 69 && grades[i] >= 67)
      {
         grades_scale[8]++;
         total_count++;
      }
      else if (grades[i] <= 66 && grades[i] >= 63)
      {
         grades_scale[9]++;
         total_count++;
      }
      else
      {
         grades_scale[10]++;
         total_count++;
      }

   }
   

   if (total_count != n)
   {
      printf("You missied something\n");
      return -1;
   }

   mean = calculate_mean(grades, n);

   variance = calculate_variance(grades, n);

   printf("Mean = %f\n", mean);
   printf("Variance = %f\n", variance);
   printf("min = %d\n", min);
   printf("max = %d\n", max);

   //printf("%-12s|%-20s|%-10s\n", "Grade Range", "Letter Grade", "Count");
   printf("Grade Range\tLetter Grade\t\tCount\n");
   printf("--------------------------------------------\n");
   printf(">= 93\t\t\tA\t\t%i\n",  grades_scale[0]);   
   printf("92 - 90\t\t\tA-\t\t%i\n",  grades_scale[1]);
   printf("89 - 87\t\t\tB+\t\t%i\n", grades_scale[2]);
   printf("86 - 83\t\t\tB\t\t%i\n", grades_scale[3]);
   printf("82 - 80\t\t\tB-\t\t%i\n", grades_scale[4]);
   printf("79 - 77\t\t\tC+\t\t%i\n", grades_scale[5]);
   printf("76 - 73\t\t\tC\t\t%i\n", grades_scale[6]);
   printf("72 - 70\t\t\tC-\t\t%i\n", grades_scale[7]);
   printf("69 - 67\t\t\tD+\t\t%i\n", grades_scale[8]);
   printf("66 - 63\t\t\tD\t\t%i\n", grades_scale[9]);
   printf("< 63\t\t\tF\t\t%i\n", grades_scale[10]);

   return 0;
}
