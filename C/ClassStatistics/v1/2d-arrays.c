#include <stdio.h>
#include <stdlib.h>
 
 
 
void print_array(const int **array, const int rows, const int cols)
{
   int i, j;
   for (i = 0; i <  rows; i++)
   {
      for (j = 0; j < cols; j++)
         printf("%d\t", array[i][j]);

      printf("\n");
   }
 
} 
 
int main(const int argc, char *argv[])
{
   int i, j, count = 0;
   
   if (argc < 3)
   {
      fprintf(stderr, "You need to pass two ints\n");
      exit(1);
   }

   int rows = atoi(argv[1]);
   int cols = atoi(argv[2]);

   // -----------------------------------------------
   //                   METHOD 1
   // -----------------------------------------------

   int *array = (int *)malloc(rows * cols * sizeof(int));
 
   for (i = 0; i <  rows; i++)
      for (j = 0; j < cols; j++)
         *(array + i*cols + j) = ++count;
 
   for (i = 0; i <  rows; i++)
   {
      for (j = 0; j < cols; j++)
         printf("%d\t", *(array + i*cols + j));

      printf("\n");
   }
   
   printf("freeing array\n");
   free(array);

  
   // -----------------------------------------------
   //                   METHOD 2
   // -----------------------------------------------

   int *array2[rows];
   for (i = 0; i < rows; i++)
      array2[i] = (int *)malloc(cols * sizeof(int));


   // Note that arr[i][j] is same as *(*(arr+i)+j)
   for (i = 0; i <  rows; i++)
      for (j = 0; j < cols; j++)
         array2[i][j] = ++count; // Or *(*(arr+i)+j) = ++count
 
   for (i = 0; i <  rows; i++)
   {
      for (j = 0; j < cols; j++)
         printf("%d\t", array2[i][j]);

      printf("\n");
   }

   printf("freeing array2\n");
   for (i = 0; i < rows; i++)
      free(array2[i]);
   


   // -----------------------------------------------
   //                   METHOD 3
   // -----------------------------------------------
   int **array3 = (int **)malloc(rows * sizeof(int *));
   for (i = 0; i < rows; i++)
   {
      array3[i] = (int *)malloc(cols * sizeof(int));
      if (array3[i] == NULL)
      {
         fprintf(stderr, "Not enough memory to allocate\n");
         exit(1);
      }
   }


   // Note that arr[i][j] is same as *(*(arr+i)+j)
   for (i = 0; i <  rows; i++)
      for (j = 0; j < cols; j++)
         array3[i][j] = ++count; // Or *(*(arr+i)+j) = ++count
 
   for (i = 0; i <  rows; i++)
   {
      for (j = 0; j < cols; j++)
         printf("%d\t", array3[i][j]);

      printf("\n");
   }

   printf("freeing array3\n");
   
   
   
   // -----------------------------------------------
   //                   METHOD 4
   // -----------------------------------------------

   int **array4;
  
   array4  = (int **)malloc(sizeof(int *) * rows);
   array4[0] = (int *)malloc(sizeof(int) * cols * rows);
 
   for(i = 0; i < rows; i++)
      array4[i] = (*array4 + cols * i);
  
   for (i = 0; i <  rows; i++)
      for (j = 0; j < cols; j++)
         array4[i][j] = ++count; // Or *(*(arr+i)+j) = ++count
 
   for (i = 0; i <  rows; i++)
   {
      for (j = 0; j < cols; j++)
         printf("%d\t", array4[i][j]);

      printf("\n");
   }

   printf("freeing array4\n");
   free(array4[0]);
   //for (i = 0; i < rows; i++)
   //   free(array4[i]);

   free(array4);
   
   print_array(array3, rows, cols);
   
   for (i = 0; i < rows; i++)
      free(array3[i]);

   free(array3);

   return 0;
}
