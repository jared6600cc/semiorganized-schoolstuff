#ifndef GRADES_DIST
#define GRADES_DIST

// grades_dist.h
typedef struct
{
   int min , max, data_size;
   float mean , median , std_dev ;
} Statistics ;


// gets the size of the data from file. 
void get_data_size(FILE *fp, int *students, int *assignments);

// gets the data from a file. 
void get_data ( FILE *fp, const int students, const int assignments, int **grades);

// bin the grades
int bin_grades (int students,  int assignments, int **grades, int **grades_scale) ;

// get stats
void get_stats (int students , int assignments, int **grades, Statistics *stats );

// print the grades
void display_grades_distribution (int assignments , int **grades_scale , Statistics *stats );

// write the grades to an output file
void write_grades_distribution (FILE *fout, FILE *fp);

//calculate final grade
double calculate_final_grade ();

//calculate letter grade
double calculate_letter_grade (char *letterGrade);

#endif
