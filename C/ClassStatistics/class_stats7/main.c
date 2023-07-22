/* Jared Bumgardner
 * Based on code provided by Prof Touma
 * Main
 */
 
 #include <stdio.h>
 #include <math.h>
 
 int main(void)
{
   int num_students, num_assignments;
   int i = 0, j = 0;

   printf("How  many assignments are there? ");
   scanf("%d", &num_assignments);

   printf("How many students are in the class?  ");
   scanf("%d", &num_students);

   int grades[num_students], grades_scale[11][num_assignments];

   struct Statistics stats[num_assignments];

   //intialize array
   for (i = 0; i < num_students; i++)
      grades[i] = 0;
   

   int total_count = 0;

   // intialize array
   for (i = 0; i < 11; i++)
      for (j = 0; j < num_assignments; j++)
         grades_scale[i][j] = 0;
   
   for (j = 0; j < num_assignments; j++)
   {
      printf("Please enter the grades for %d students for assignment # %i:\n", num_students, j+1);

      get_user_input(grades, num_students);
      bin_grades(num_students, grades, i, grades_scale);

      if (total_count != num_students)
      {
         printf("You missied something\n");
         return -1;
      }

      total_count = 0;
	  
	  get_stats(grades, j, i, stats); 

   }
   
   display_grades_distribution(num_assignments, grades_scale, stats);



   return 0;
}
