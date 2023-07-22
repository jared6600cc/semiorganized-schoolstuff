//Study for test2

#include<stdio.h>

int main(void){
	
	//1-d arrays
	printf("/t1-Dimensional Arrays Practice\n");
	
	int grades[100];										//declaration of int array
	printf("Int Array Initialization: SUCCESS\n");
	
	int grades2[3] = {1,2,3};								//declaration of int array & all elements
	printf("Int Array All Elements Initialization: SUCCESS\n");
	
	char letters[5] = {'a','b','c','d','e'};				//declaration of char array & all elements
	printf("Char Array All Elements Initialization: SUCCESS\n");
	
	int ints[5] = {1,2,3};									//declaration of int array and some elements
	printf("Int Array Some Elements Initialization: SUCCESS\n");
	
	//n-d arrays
	printf("/tMulti-Dimensional Arrays Practice\n");
	
	int gradesMD[2][2];										//declaration of int arrayMD
	printf("Int ArrayMD Initialization: SUCCESS\n");

	int arrayAllElements[2][2] = {							//declaration of int arrayMD and all elements
		{1, 2},
		{3, 4}
	};
	printf("Int ArrayMD All Elements Initialization: SUCCESS\n");

	
	int arraySomeElements[2][2] = {							//declaration of int arrayMD and some elements
		{1, 2}
	};
	printf("Int ArrayMD Some Elements Initialization: SUCCESS\n");
	
	return 0;
}