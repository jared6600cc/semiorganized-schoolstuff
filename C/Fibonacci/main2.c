//   Jared Bumgardner
//   COP 3530 - Prof. Mishra
//   Definition: This file implements a function for obtaining/printing
//	 the fibonacci square sequence as well as a main function which utilizes it.
//   9/12/2016

#include <stdio.h>

double fibonacci(int numTerms, int currTerm){
	//declarations
	double newTerm;
	
	//calculate & print fibonacci sequence to user defined term
	while(currTerm != numTerms){
		if(currTerm == 0){
			newTerm = 0;
			printf("\n***currTerm == 0\n");
			printf("%f\n",newTerm);
			currTerm++;
			}
			else if(currTerm == 1){
				newTerm = 1;
				printf("\n***currTerm == 1\n");
				printf("%f\n",newTerm);
				currTerm++;
				}
				else{
					printf("\n**currTerm == ELSE\n");
					newTerm = fibonacci(numTerms, currTerm - 1) + fibonacci(numTerms, currTerm - 2);
					printf("%\f",newTerm);
					currTerm++;
					}
				}
					
	return newTerm;
}

void main(){
	//declarations
	int userTermNum;
	
	//introduction
	printf("\n\t***FIBONACCI SEQUENCE-ATOR***");
	printf("\n\t---This program calculates the fibonacci square sequence\n\t---up until a user specified term.");
		
	//calculate user's fibonacci sequence
	printf("\n\n\tPlease enter up to what # term\n\tyou would like to generate the fibonacci square sequence:\n");
	scanf("%d",&userTermNum);
	
	fibonacci(userTermNum, 0);
}