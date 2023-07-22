/*
 * Jared Bumgardner
 *
 * HW02
 *
 * Display an inverted pyramid with user given number of rows
 *
 * Compile : gcc -o inverted_pyramid.x inverted_pyramid.c
 * Run : ./inverted_pyramid.x
 * 
 */
 
 #include <stdio.h>
 
 int main(void){
	 
	 //declare variables
	 int height_Rows;
	 int current_Row = 1;
	 int num_Spaces = 0;
	 int num_Stars;
	 int height_Current;
	 int i;
	 
	 //introduce program
	 printf("\n\t***Welcome to the Inverted Pyramid Generator***\n");
	 
	 //prompt user for desired number of rows
	 printf("\n\tPlease enter the pyramid's height in rows: \n");
	 scanf("%d" , &height_Rows);
	 printf("\n\n");
	 height_Current = height_Rows;
	 
	 //index through pyramid by row
	 for (current_Row; current_Row <= height_Rows; current_Row++) {
		 //determine the number of stars
		 num_Stars = (2 * height_Current) - 1;
		 
		 //print white spaces
		 for (i = 0; i < num_Spaces; i++) {
			 printf("   ");
		 }
		 
		 //print pyramid contents
		 for (i = 0; i < num_Stars; i++) {
			 printf(" * ");
		 }
		 
		 //print final white spaces
		 for (i = 0; i < num_Spaces; i++) {
			 printf("   ");
		 }
		 //increment number of spaces & go to next row
		 num_Spaces++;
		 height_Current--;
		 printf("\n");
		 
	 }	 
 }