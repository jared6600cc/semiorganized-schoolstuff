/*
 * Jared Bumgardner
 *
 * HW02
 *
 * Count the digits of a number that the user enters
 *
 * Compile : gcc -o count_digits.x count_digits.c
 * Run : ./count_digits.x
 * 
 */
 
 #include <stdio.h>
 
 int main(void) {
	 
	 //declare variables
	 long user_Number;
	 long temp_Number;
	 int digit_Count = 0;
	 
	 //introduce program
	 printf("\n\t***Digit Counter***\n\n");
	 
	 //prompt user for number to count
	 printf("\tPlease enter a number that you'd like counted: ");
	 scanf("%li" , &user_Number);
	 temp_Number = user_Number;
	 
	 //count the number of digits
	 do {
		 temp_Number = temp_Number/10;
		 digit_Count++;
	 } while (temp_Number >= 1);
	 
	 //print results
	 printf("%i" , digit_Count);
	 
	 return 0;
 }