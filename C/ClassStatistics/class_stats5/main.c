/* 
 * Jared Bumgardner
 * Based on code by Jimmy Touma
 * HM06 MAIN file
 */
 
 #include <stdio.h>
 #include <math.h>

//
//
//
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


      if (total_count != num_students)
      {
         printf("You missied something\n");
         return -1;
      }

      total_count = 0;
      stats[j].mean = calculate_mean(grades, num_students);
      stats[j].variance = calculate_variance(grades, num_students);
      stats[j].median = calculate_median(grades, num_students);
      stats[j].min = calculate_min(grades,num_students);
      stats[j].max = calculate_max(grades, num_students);
      stats[j].num_of_students = num_students;

   }
   
   display_grades_distribution(num_assignments, grades_scale, stats);



   return 0;
}
