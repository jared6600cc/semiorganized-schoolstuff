/* Jared Bumgardner based on
 * Brett O'Dea's
 * HW08 
 * March 29, 2016
 * Main.c Reads a file and counts the number of lines and tokens to allocate an array and display grades distribution for the class statistics. 
 * To run the make use "./grades_dist.exe" and enter file name on command line.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "stats.h"
#include "grades_dist.h"

int main(int argc, char *argv[])
{
	
	if (argc < 2)
	{
		fprintf(stderr, "Please input a csv file name\n");
		return(1);
		}

	FILE *fp, *fout; 									//CHANGED
    printf("the input file name is %s\n",  argv[1]);
	if(fp == NULL) 
		{
			perror("Error in opening file \n");
			return(-1);
		}
		
    // open file in read mode
    fp = fopen(argv[1], "r");
	fout = fopen(argv[2], "w");							//CHANGED
	if(fout == NULL) {									//CHANGED
		perror("Error in opening output file %s\n");	//CHANGED
		return(-1);										//CHANGED
	}
	
	// set pointers
	fseek(fp, 0, SEEK_SET);								//CHANGED
	fseek(fout, 0, SEEK_SET);							//CHANGED
	
	int i, j, total_count, assignments, students;

	
	// Gets the number of students and assignments.
	get_data_size(fp, &students, &assignments);
	
	
	//Allocates sizes for the grades array and initializes it. 
	int **grades = (int **)malloc(assignments * sizeof(int *));
	for (i = 0; i < assignments; i++)
	{
		grades[i] = (int *)malloc(students * sizeof(int));
		if (grades[i] == NULL)
		{
			fprintf(stderr, "Not enough memory to allocate\n");
			exit(1);
		}
	}
	// Allocates the size of the grades_scale array and initializes it. 
	int **grades_scale = (int **)malloc(assignments * sizeof(int *));
	for (i = 0; i < assignments; i++)
		{
			grades_scale[i] = (int *)malloc(11 * sizeof(int));
			if (grades_scale[i] == NULL)
			{
				fprintf(stderr, "Not enough memory to allocate\n");
				exit(1);
			}
		}
		
	Statistics	stats[assignments];
	
	//Initialize Arrays
	for (i = 0; i <  assignments; i++)
		for (j = 0; j < students; j++)
			grades[i][j] = 0;
	
	for (i = 0; i <  assignments; i++)
		for (j = 0; j < 11; j++)
			grades_scale[i][11] = 0;
		
		
	// Grabs the data from the file and fills the grades array. 
	get_data(fp, students, assignments, grades);
	
	// Loops through assignments and students per assignment to bin the grades. 
	bin_grades(students, assignments, grades, grades_scale);
	
	// Calculates the statistics for all the students for each assignment.
	get_stats(students, assignments ,grades , stats);
	
	// Prints the results. 
    display_grades_distribution(assignments, grades_scale, stats);
/*TODO*/

	// Write results to output file
	write_grades_distribution (assignments, grades_scale, stats, fout, fp);		//CHANGED
	
   for (i = 0; i < students; i++)
      free(grades[i]);

   free(grades);
   
   // Close the file. 
   fclose(fp);
   fclose(fout);										//CHANGED

   return 0;
}
