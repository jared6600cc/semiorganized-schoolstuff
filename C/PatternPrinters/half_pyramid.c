/*
 * Jared Bumgardner
 *
 * HW02
 *
 * Display a half pyramid with user given number of rows
 *
 * Compile : gcc -o half_pyramid.x half_pyramid.c
 * Run : ./half_pyramid.x
 * 
 */
 
 #include <stdio.h>
 
 int main(void){
	 
	 //declare variables
	 int num_Rows;
	 int current_Row;
	 int i;
	 int line_Constructor;
	 
	 //introduce program
	 printf("\n\t***Welcome to the Half Pyramid Generator***\n\n");
	 
	 //prompt user for number of rows
	 printf("\tPlease enter the pyramid's height in rows: \n");
	 scanf("%d" , &num_Rows);

	 //index by row
	 for (i = 1; i <= num_Rows; i++) {
		 line_Constructor = 1;		//reset traversing variables
		 printf("\n");				//go to new line
		 
		 //construct and print contents of the row 
		 while (line_Constructor <= i) {
			 printf("%d " , line_Constructor);
			 line_Constructor++;
		 }
	 }
	 	 
	 return 0;
 }