/* Jared Bumgardner
 * Based on code provided by Prof Touma
 * Statistics structure & function prototypes
 */
 
 #ifndef CLASS_STATS
 #define CLASS_STATS
 
 // structure that holds the statistics for an assignment
typedef struct
{
   int min, max, num_of_students;
   float mean, median, variance;
} Statistics;

//sort the values of an array in ascending order
//input are the array to be sorted and the number of elements in the array
void sort_a(int *array, int num_elements);

//calculate the mean of the elements of an array
//input are the array of data and the number of elements in the array; return the mean
float calculate_mean(const int *array, int num_elements);

//calculate the variance of the elements of an array
//input are the array of data and the number of elements in the array
//this function calls calculate_mean; returns the variance
float calculate_variance(const int *array, int num_elements);

//calculate the median of the elements of an array
//input are the array of data and the number of elements in the array
//the input array is not necessarily sorted; it calls sort_a first to sort a copy of the array then
//computes the median and return it
float calculate_median(const int *array, int num_elements);

//finds the maximum value of the elements of an array
//input are the array of data and the number of elements in the array; returns the maximum element
int calculate_max(const int *array, int num_elements);

//finds the minimum value of the elements of an array
//input are the array of data and the number of elements in the array; returns the minimum element
int calculate_min(const int *array, int num_elements);

//gets the grades of n students for an assignment from the user
//input are the array that hold the grades and the number of students; it modifies the array
void get_user_input(int *array, int num_elements);

//bin the grades
//input are the grades array to be binned andits size; the arrays holding the binned grades and its
//size
//returns the total number of grades binned
int bin_grades(int num_students, const int *grades, int assignment, int grades_scale[11][
	assignment]);
	
//get stats
//input are the grades array and its size along with the statistics structure and the assignment that
//the stats
//are being computed for the structure gets modified inside the function
void get_stats(const int *grades, int num_elements, int assignment, Statistics *stats);

//print the grades
//input are the binned array and its size and the statistics structure and its size
void display_grades_distribution(int num_assignments, const int grades_scale[11][num_assignments],
	Statistics *stats);
	
#endif