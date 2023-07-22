//   Jared Bumgardner
//   COP 3530 - Prof. Mishra
//	 This file implements the linearSearch func. and main
//   8/25/2016

#include <stdio.h>

int linearSearch(int *inArray, int elements, int findme){
	
	//declare variables
	int i = 0;
	int isFound = 0;
	
	//search array for value
	for(i = 0; i < elements; i++){
		
		if(inArray[i] == findme){
			isFound = 1;
			break;
		}
		else
			isFound = 0;
	}
	
	return isFound;
}

void main(){
	
	//declare variables
	int findme, numberfound;
	int data[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,
				  47,53,59,61,67,71,73,79,83,89,97,101};
				  
	int size = (sizeof(data)/sizeof(int));
	
	//introduce program
	printf("\n\n\t\t***Is this number a Prime Number < 110***");

	//get user number to find
	printf("\n\tIs THIS number a prime that is < 110? \n");
	scanf("%d", &findme);
	
	numberfound = linearSearch(data, size, findme);
	printf("\n(1:True\t0:False)\nFunction found the number: %i\n", numberfound);
	
	return;
}