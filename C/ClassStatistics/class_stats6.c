/*
 * Jared Bumgardner
 *
 * HW03
 *
 * Take the average,
 * Take the variance,
 * Find the highest,
 * and find the lowest grade of
 * a number of user inputed grades
 *
 * Compile : gcc -o class_stats.x class_stats.c
 * Run : ./class_stats.x
 * 
 */
 
 #include <stdio.h>
 
 int main(void) {
	 
	 //declare variables
	 int grades_quantity;
	 int i;
	 int grade_number;
	 double grade_average = 0;
	 double grade_variance = 0;
	 double temp_variance = 0;
	 double maximum_grade = 0;
	 double minimum_grade = 0;
	 int grade_distribution [12] = { 0 };
	 int running_total = 0;
	 
	 //initialize string arrays
	 char *grade_range[] = {
		 "100-93", "92-90", "89-87", "86-83", "82-80", "79-77", 
		 "76-73", "72-70", "69-67", "66-63", "< 63"
	 };
	 
	 char *letter_grade[] = {
		 "A", "A-", "B+", "B", "B-", "C+", 
		 "C", "C-", "D+", "D", "F"
	 };	 
	 
	 //introduce program
	 printf("\n\t***Class Statistics Machine***");
	 
	 //prompt user for number of grades to evaluate
	 printf("\n\tPlease print the number of grades you will be evaluating: ");
	 scanf("%d", &grades_quantity);
	 grade_number = i + 1;
	 printf("\n");
	 double grades [grades_quantity];
	 
	 //prompt user for grades
	 for (i = 0; i < grades_quantity; i++) {
		 printf("\t\tPlease input grade #%d: ", grade_number);
		 scanf("%lf", &grades[i]);
		 grade_number++;
	 }	 
	 
	 //take the average
	 for (i = 0; i < grades_quantity; i++) {
		 grade_average = grade_average + grades[i];
	 }
	 grade_average = grade_average / grades_quantity;
	 printf("\n\tThe average of the grades is %.2lf", grade_average);
	 
	 //take the variance
	 for (i = 0; i < grades_quantity; i++) {
		 temp_variance = grades[i] - grade_average;
		 temp_variance = temp_variance * temp_variance;
		 grade_variance = grade_variance + temp_variance;
	 }
	 grade_variance = grade_variance / (grades_quantity - 1);
	 printf("\n\tThe variance of the grades is %.2lf", grade_variance);
	 
	 //find the highest number
	 for (i = 0; i < grades_quantity; i++) {
		 if (grades[i] > maximum_grade) {
			 maximum_grade = grades[i];
		 }
	 }
	 printf("\n\tThe highest grade is %.2lf", maximum_grade);
	 
	 //find the lowest number
	 minimum_grade = maximum_grade;
	 
	 for (i = 0; i < grades_quantity; i++) {
		 if (grades[i] < minimum_grade) {
			 minimum_grade = grades[i];
		 }
	 }
	 printf("\n\tThe lowest grade is %.2lf", minimum_grade);

	 //categorize grades
	 for (i = 0; i < grades_quantity; i++) {
		 if (grades[i] >= 93) {
			 grade_distribution[0]++;
			 running_total++;
		 }
		 else if (grades[i] >= 90 && grades[i] <= 92) {
			 grade_distribution[1]++;
			 running_total++;
		 }
		 else if (grades[i] >= 87 && grades[i] <= 89) {
			 grade_distribution[2]++;
			 running_total++;
		 }
		 else if (grades[i] >= 83 && grades[i] <= 86) {
			 grade_distribution[3]++;
			 running_total++;
		 }
		 else if (grades[i] >= 80 && grades[i] <= 82) {
			 grade_distribution[4]++;
			 running_total++;
		 }
		 else if (grades[i] >= 77 && grades[i] <= 79) {
			 grade_distribution[5]++;
			 running_total++;
		 }
		 else if (grades[i] >= 73 && grades[i] <= 76) {
			 grade_distribution[6]++;
			 running_total++;
		 }
		 else if (grades[i] >= 70 && grades[i] <= 72) {
			 grade_distribution[7]++;
			 running_total++;
		 }
		 else if (grades[i] >= 67 && grades[i] <= 69) {
			 grade_distribution[8]++;
			 running_total++;
		 }
		 else if (grades[i] >= 63 && grades[i] <= 66) {
			 grade_distribution[9]++;
			 running_total++;
		 }
		 else {
			 grade_distribution[10]++;
			 running_total++;
		 }
	 }
	 
	 //display results
	 printf("\n\n\t\tGrade Distribution");
	 printf("\n\tGrade Range   Letter Grade   Count");
	 for (i = 0; i < 11; i++) {
		 printf("\n\t%-11s   %-12s   %-d", grade_range[i], letter_grade[i], grade_distribution[i]);
	 }
	 
	 printf("\n\n\tTotal #: %d", running_total);
	 
	 return 0;
 }