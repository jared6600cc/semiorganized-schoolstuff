/*
 * Jared Bumgardner
 * based on code by Jimmy Touma
 * HM05
 *
 * gcc input.c -lm
 *
 * I am aware that there are portions of this that do not work as intended;
 * the variance (which used to work but suddenly started returning zeros) 
 * perplexes me and I cannot see what is causing my binning to have issues. 
 * I apologize.
 *
 */
 
 #include <stdio.h>
 #include <math.h>
 
		//define structures
 struct Stats
{
	float mean;
	float median;
	float variance;
	int minimum_grade;
	int maximum_grade;
	int amount_grades;
};
 
		//define functions
 //sort given array
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

//calculate the mean of given array
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

//calculate the variance of given array
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

//calculate the median of given array
float calculate_median(int grades[], int n) {
	//declare variables
	float remainder = n % 2;
	float median;
	
	//sort array
	sort_array(grades, n);
	
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

//calculate the minimum grade of given array
int calculate_min(int grades[], int n) {
	//sort array of grades
	sort_array(grades, n);
	
	//get min
	return grades[0];
}

//calculate the maximum grade of given array
int calculate_max(int grades[], int n) {
	//sort array of grades
	sort_array(grades, n);
	
	//get max
	return grades[n-1];
}

//get grades for grades array
void get_user_input(int grades[], int n) {
	
	int i;			//index for looping through grades
	
	//get grades data for current assignment
	for (i = 0; i < n; i++)
		{
		printf("Please enter a grade between 0 and 100 for student # %i: ", i+1);
		scanf("%d", &grades[i]);
	}
}
 
 //display output of stats
void display_grades_distribution(int m, int grades_scale[11][m], struct Stats stats[]) {
	
	int i = 0;		//index for printf
	
	//display assignment statistics
	printf("\n\t----------------------\n");
	printf("\t **Class Statistics**\n");
	printf("\t----------------------\n");
	
	printf("Mean            ");					//print means	
	while (i != m) {
		printf("  %-5.0f", stats[i].mean);
		i++;
	}
	if (i = m) {
		printf("\n");
		i = 0;
	}
	
	printf("Median          ");					//print median
	while (i != m) {
		printf("  %-5d ", stats[i].median);
		i++;
	}
	if (i = m) {
		printf("\n");
		i = 0;
	}
	
	printf("Variance        ");					//print variance
	while (i != m) {
		printf("  %-5.0f ", stats[i].variance);
		i++;
	}
	if (i = m) {
		printf("\n");
		i = 0;
	}
	
	printf("Min             ");					//print min grade
	while (i != m) {
		printf("  %-5.0d ", stats[i].minimum_grade);
		i++;
	}
	if (i = m) {
		printf("\n");
		i = 0;
	}
	
	printf("Max             ");					//print max grade
	while (i != m) {
		printf("  %-5.0d ", stats[i].maximum_grade);
		i++;
	}
	if (i = m) {
		printf("\n");
		i = 0;
	}
	
	printf("# of Students   ");					//print # of students
	while (i != m) {
		printf("  %-5.0d ", stats[i].amount_grades);
		i++;
	}
	if (i = m) {
		printf("\n");
		i = 0;
	}
			
	//display grade distribution
	printf("\n\t----------------------\n");
	printf("\t**Grade Distribution**\n");
	printf("\t----------------------\n");
	
	printf("100 - 93        ");
	while (i != m) {
		printf("  %-5d", grades_scale[1][i]);
		i++;
		
	}
	if (i = m) {
		printf("\n");
		i = 0;
	}
	
	printf("92 - 90         ");
	while (i != m) {
		printf("  %-5d", grades_scale[2][i]);
		i++;
	}
	if (i = m) {
		printf("\n");
		i = 0;
	}
	
	printf("89 - 87         ");
	while (i != m) {
		printf("  %-5d", grades_scale[3][i]);
		i++;
	}
	if (i = m) {
		printf("\n");
		i = 0;
	}
	
	printf("86 - 83         ");
	while (i != m) {
		printf("  %-5d", grades_scale[4][i]);
		i++;
	}
	if (i = m) {
		printf("\n");
		i = 0;
	}
	
    printf("82 - 80         ");
	while (i != m) {
		printf("  %-5d", grades_scale[5][i]);
		i++;
	}
	if (i = m) {
		printf("\n");
		i = 0;
	}
	
    printf("79 - 77         ");
	while (i != m) {
		printf("  %-5d", grades_scale[6][i]);
		i++;
	}
	if (i = m) {
		printf("\n");
		i = 0;
	}
	
    printf("76 - 73         ");
	while (i != m) {
		printf("  %-5d", grades_scale[7][i]);
		i++;
	}
	if (i = m) {
		printf("\n");
		i = 0;
	}
	
    printf("72 - 70         ");
	while (i != m) {
		printf("  %-5d", grades_scale[8][i]);
		i++;
	}
	if (i = m) {
		printf("\n");
		i = 0;
	}
	
    printf("69 - 67         ");
	while (i != m) {
		printf("  %-5d", grades_scale[9][i]);
		i++;
	}
	if (i = m) {
		printf("\n");
		i = 0;
	}
	
    printf("66 - 63         ");
	while (i != m) {
		printf("  %-5d", grades_scale[10][i]);
		i++;
	}
	if (i = m) {
		printf("\n");
		i = 0;
	}
	
    printf("63 - 0          ");
	while (i != m) {
		printf("  %-5d", grades_scale[11][i]);
		i++;
	}
	if (i = m) {
		printf("\n");
		i = 0;
	}
}

 int main(void) {
 
 int n = 0;					//number of students
 int num_assign = 0;		//number of assignments
 int i = 0;					//index for assignment loop
 int j = 0;					//index for bin grade loop
 int min_grade = 0;			//minimum grade of current grade array
 int max_grade = 0;			//maximum grade of current grade array
 float median = 0;			//median of current grades array
 float mean = 0;			//mean of current grades array
 float variance = 0;		//variance of current grades array
 
 
 //get user input
   printf("How many students are in the class?  ");		//number of students
   scanf("%d", &n);
   printf("How many assignments are there? ");			//number of assignments
   scanf("%d", &num_assign);
 
 //create holder array for assignment stat structures
 struct Stats stats[num_assign];				//create structure holding stats
 int grades[n];											//holds grades
 int grades_scale[11][num_assign];						//bin for total grades
 int total_count = 0;									//total count of grades

 
 //initialize array
  for (i = 0; i < n; i++)								//initialize grades to zero
      grades[i] = 0;
	  
   for (i = 0; i < 11; i++){								//initialize grades_scale
	  for (j = 0; j < num_assign; j++) {
		  grades_scale[i][j] = 0;
	  }
  }
  
  for (i = 0; i < num_assign; i++) {					//loop through assignments  
  
  //get the grades
  	printf("\n\t***Assignment #%d***\n", i+1);
	get_user_input(grades, n);
  
  //bin the grades and update/store accordingly
	for (j = 0; j < n; j++) {							//index through current assignment
		if (grades[i] >= 93)
		{
			grades_scale[0][i]++;
			total_count++;
		}
		else if (grades[i]<= 92 && grades[i] >= 90)
		{
			grades_scale[1][i]++;
			total_count++;
		}
		else if (grades[i] <= 89 && grades[i] >= 87)
		{
			grades_scale[2][i]++;
			total_count++;
		}
		else if (grades[i] <= 86 && grades[i] >= 83)
		{
			grades_scale[3][i]++;
			total_count++;
		}
		else if (grades[i] <= 82 && grades[i] >= 80)
		{
			grades_scale[4][i]++;
			total_count++;
		}
		else if (grades[i] <= 79 && grades[i] >= 77)
		{
			grades_scale[5][i]++;
			total_count++;
		}
		else if (grades[i] <= 76 && grades[i] >= 73)
		{
			grades_scale[6][i]++;
			total_count++;
		}
		else if (grades[i] <= 72 && grades[i] >= 70)
		{
			grades_scale[7][i]++;
			total_count++;
		}
		else if (grades[i]<= 69 && grades[i] >= 67)
		{
			grades_scale[8][i]++;
			total_count++;
		}
		else if (grades[i] <= 66 && grades[i] >= 63)
		{
			grades_scale[9][i]++;
			total_count++;
		}
		else
		{
			grades_scale[10][i]++;
			total_count++;
		}
	}
  
  
  //calculate stats and update/store accordingly 
  mean = calculate_mean(grades, n);
  stats[i].mean = mean;
  
  median = calculate_median(grades, n);
  stats[i].median = median;

  variance = calculate_variance(grades, n);
  stats[i].variance = variance;
  
  min_grade = calculate_min(grades, n);
  stats[i].minimum_grade = min_grade;
  
  max_grade = calculate_max(grades, n);
  stats[i].maximum_grade = max_grade;
  
  total_count = n;
  stats[i].amount_grades = total_count;
    
	}
  //display output
  display_grades_distribution(num_assign, grades_scale, stats);  
 
  return 0;
  }