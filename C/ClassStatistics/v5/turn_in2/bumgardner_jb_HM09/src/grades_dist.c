/* Jared Bumgardner
 * Based on Brett O'Dea's HM08
 *This is the implementation of the grades_dist header file
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "stats.h"
#include "grades_dist.h"

// structure that holds the statistics for an assignment
void get_data_size(FILE *fp, int *students, int *assignments)
{
	char line[1024] = {0x0};
	char name[100] = {0x0};
	int i, j, count;
	int rows = 0, cols = 0; 
	
	while(fgets(line, 1023, fp)) // counts the rows
	{
		rows++;
	}
	
	fseek(fp, 0, SEEK_SET);
	
	char delims[] = ",";
	char *tok = strtok( line, delims );
	while( tok != NULL )  // counts the columns
    {
	   cols++;
       tok = strtok( NULL, delims );
    }
	
    *students = rows - 1;
	*assignments = cols - 1;
}

void get_data( FILE *fp, int students, int assignments, int **grades)
{
	int i, j, k, count; 
	char line[1024] = {0x0};
	char name[100] = {0x0};

	fseek(fp, 0, SEEK_SET);
	char delims[] = ",";
	char *tok = strtok( line, delims );
	
	fgets(line, 1023, fp);
	tok = strtok( line, delims );
	
	for (i = 0; i < students; i++)
	{
		fgets(line, 1023, fp);
	    tok = strtok( line, delims );
 		for (j = 0; j < assignments; j++)
		{
			tok = strtok( NULL, delims);
			k = atoi(tok); 
			grades[j][i] = k; 
	    }
    }
}

int bin_grades ( int students ,int assignments, int **grades, int **grades_scale) 
{
	int i, j;
	int total_count = 0;
	
	
	for (i = 0; i < assignments; i++)
	{
	   for (j = 0; j < students; j++)
      {
         if (grades[i][j] >= 93)
         {
            grades_scale[i][0]++;
            total_count++;
         }
         else if (grades[i][j]<= 92 && grades[i][j] >= 90)
         {
            grades_scale[i][1]++;
            total_count++;
         }
         else if (grades[i][j] <= 89 && grades[i][j] >= 87)
         {
            grades_scale[i][2]++;
            total_count++;
         }
         else if (grades[i][j] <= 86 && grades[i][j] >= 83)
         {
            grades_scale[i][3]++;
            total_count++;
         }
         else if (grades[i][j] <= 82 && grades[i][j] >= 80)
         {
            grades_scale[i][4]++;
            total_count++;
         }
         else if (grades[i][j] <= 79 && grades[i][j] >= 77)
         {
            grades_scale[i][5]++;
            total_count++;
         }
         else if (grades[i][j] <= 76 && grades[i][j] >= 73)
         {
            grades_scale[i][6]++;
            total_count++;
         }
         else if (grades[i][j] <= 72 && grades[i][j] >= 70)
         {
            grades_scale[i][7]++;
            total_count++;
         }
         else if (grades[i][j]<= 69 && grades[i][j] >= 67)
         {
            grades_scale[i][8]++;
            total_count++;
         }
         else if (grades[i][j] <= 66 && grades[i][j] >= 63)
         {
            grades_scale[i][9]++;
            total_count++;
         }
         else
         {
            grades_scale[i][10]++;
            total_count++;
         }
      }
	}

	
   

}


void get_stats (int students , int assignments, int **grades, Statistics *stats )
{
	int i, j;
	
	
	for (i = 0; i < assignments; ++i)
	{
		for (j = 0; j < students; j++)
		{
			stats[i].mean = calculate_mean(grades[i], students);
			stats[i].std_dev = sqrt(calculate_variance(grades[i], students));
			stats[i].median = calculate_median(grades[i], students);
			stats[i].min = calculate_min(grades[i],students);
			stats[i].max = calculate_max(grades[i], students);
			stats[i].data_size = students;
		}
	}
}

void display_grades_distribution(int assignments , int **grades_scale , Statistics *stats )
{

   int i;

   printf("\n");
   printf("\n");
   printf("%-25s", "Assignment #:");
   for (i = 0; i < assignments; i++)
      printf("%-10i", i + 1);
   
   printf("\n");
   for (i = 0; i < 25; i++)
      printf("=");
   for (i = 0; i < 10*assignments; i++)
      printf("=");
   printf("\n");
   printf("\n");

   printf("%-25s", "Mean:");
   for (i = 0; i < assignments; i++)
      printf("%-10.2f", stats[i].mean);
   printf("\n");

   printf("%-25s", "Median :");
   for (i = 0; i < assignments; i++)
      printf("%-10.2f", stats[i].median);
   printf("\n");

   printf("%-25s", "Variance:");
   for (i = 0; i < assignments; i++)
      printf("%-10.2f", stats[i].std_dev);
   printf("\n");

   printf("%-25s", "Min:");
   for (i = 0; i < assignments; i++)
      printf("%-10d", stats[i].min);
   printf("\n");

   printf("%-25s", "Max:");
   for (i = 0; i < assignments; i++)
      printf("%-10d", stats[i].max);
   printf("\n");

   printf("%-25s", "# of Students:");
   for (i = 0; i < assignments; i++)
      printf("%-10d", stats[i].data_size);
   printf("\n");

   for (i = 0; i < 25; i++)
      printf("=");
   for (i = 0; i < 10*assignments; i++)
      printf("=");
   printf("\n");
   printf("%-15s%-10s", "Scale", "Grade");
   for (i = 0; i < assignments; i++)
      printf("%-10s", "Count");
   printf("\n");
   for (i = 0; i < 25; i++)
      printf("=");
   for (i = 0; i < 10*assignments; i++)
      printf("=");
   printf("\n");
   printf("%-15s%-10s", ">= 93", "A");
   for (i = 0; i < assignments; i++)
      printf("%-10d", grades_scale[i][0]);
   printf("\n");

   printf("%-15s%-10s", "92 - 90", "A-");
   for (i = 0; i < assignments; i++)
      printf("%-10d", grades_scale[i][1]);
   printf("\n");

   printf("%-15s%-10s", "89 - 87", "B+");
   for (i = 0; i < assignments; i++)
      printf("%-10d", grades_scale[i][2]);
   printf("\n");
   
   printf("%-15s%-10s", "86 - 83", "B");
   for (i = 0; i < assignments; i++)
      printf("%-10d", grades_scale[i][3]);
   printf("\n");

   printf("%-15s%-10s", "82 - 80", "B-");
   for (i = 0; i < assignments; i++)
      printf("%-10d", grades_scale[i][4]);
   printf("\n");

   printf("%-15s%-10s", "79 - 77", "C+");
   for (i = 0; i < assignments; i++)
      printf("%-10d", grades_scale[i][5]);
   printf("\n");

   printf("%-15s%-10s", "76 - 73", "C");
   for (i = 0; i < assignments; i++)
      printf("%-10d", grades_scale[i][6]);
   printf("\n");

   printf("%-15s%-10s", "72 - 70", "C-");
   for (i = 0; i < assignments; i++)
      printf("%-10d", grades_scale[i][7]);
   printf("\n");

   printf("%-15s%-10s", "69 - 67", "D+");
   for (i = 0; i < assignments; i++)
      printf("%-10d", grades_scale[i][8]);
   printf("\n");

   printf("%-15s%-10s", "66 - 63", "D");
   for (i = 0; i < assignments; i++)
      printf("%-10d", grades_scale[i][9]);
   printf("\n");

   printf("%-15s%-10s", "< 63", "F");
   for (i = 0; i < assignments; i++)
      printf("%-10d", grades_scale[i][10]);
   printf("\n");
}

void write_grades_distribution (FILE *fout, FILE *fp)
{
	int c;
	int i;
	int lineNum = 1;
	char lineCurrent[256] = {0x0};
	char letterGrade[2];
	double finalGrade;
	
	while( (c = getc(fp)) != EOF ) {
		//take line from original file
		while( (c = getc(fp)) != '\n' ){
			lineCurrent[i] = getc(fp);
			i++;
			}

			//print original line to output file
			fputs(lineCurrent, fout);
	
			//append to end by line
			switch (lineNum) {
				case 1:
				fprintf(fout, "%s,Final Grade,Letter Grade", lineCurrent);
				break;
		
				case 2:
				fprintf(fout, "%s", lineCurrent);
				break;
		
				default:
				//calculate the final grade
				finalGrade = calculate_final_grade();
				
				//calculate the letter grade
				calculate_letter_grade(letterGrade);
				
				//print output
				fprintf(fout, "%s,%i,%s", lineCurrent, finalGrade, letterGrade);
				break;
		
		}	
	}
}

//calculate final grade
double calculate_final_grade (){
	/*TODO*/
	//Call function to parse out assignment weights
	//Parse out assignment grades
	//Calculate final grade
	printf("Final Grade Would Be Calculated Here");
}

//calculate letter grade
double calculate_letter_grade (char *finalGrade){
	/*TODO*/
	//Use switch statement based off of final grade from previous function
	printf("Letter Grade Would Be Calculated Here");
}

//parse assignment weights from input file
void parse_assignment_weights (FILE *fp){
	/*TODO*/
	//declare automatic array
	//go to second line
	//parse using tokens
	//save values into array
}


