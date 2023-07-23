//   Jared Bumgardner
//   COP 3530 - Prof. Mishra
//   Definition: This file implements bubblesort, selection sort
//	 and insertion sort functions as well as the main which utilizes them.
//   9/21/2016

#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int givenArray[], int numElement){
	
	//declarations
	int i, j, valueTemp;
	
	//perform indexes through array to bubbleSort
	for(j = 0; j < numElement; j++)
		for(i = 0; i < numElement; i++){
			if(givenArray[i] > givenArray[i+1]){
				valueTemp = givenArray[i];
				givenArray[i] = givenArray[i+1];
				givenArray[i+1] = valueTemp;
				
				//display array at current step
				printf("\n\t");
				for(i = 0; i <= numElement; i++)
					printf("%d ", givenArray[i]);
			}
		}
	
	return;
}

void selectionSort(int givenArray[], int numElement){
	
	//declarations
	int i, j, k, temp, sorted;
	int *minPTR = &givenArray[0];		//points to current minimum index
	int currMin = 0;					//current minimum value in array
	
	//index through the array to selectionSort
	do{
		for(i = 0; i <= numElement; i++){
			for(j = i + 1; j <= numElement; j++){
				if(givenArray[i] > givenArray[j]){
					temp = givenArray[i];
					givenArray[i] = givenArray[j];
					givenArray[j] = temp;
					
					//display array at each iteration through
					printf("\n\t");
					for(k = 0; k <= numElement; k++)
						printf("%d ", givenArray[k]);
					
					sorted = 0;
				}
				else
					sorted = 1;
			}
		}
		
	}while(sorted != 1);
	
	return;
}

void insertionSort(int givenArray[], int numElement){
	
	//declarations
	int i;
	int currValSort;
	int sorted[numElement], unsorted[numElement];
	
	//constructoin message
	printf("ERROR: Insertion sort is currently unavailable/unimplemented.");
	
	//"
	//if it is the first element, it is already sorted
	//pick new element
	//compare with all elements in the sorted sublist
	//shift all the elements in the sorted sublist that is greater than the value to be sorted
	//insert the value
	//repeat until list is sorted
	//" - internet source
	
	return;
}

void main(){
	
	//declarations
	int i, n, alg;
	int userAlg;
	
	//introduction of program
	printf("\n\t\t***Sorting Algorithms***");
	printf("\n\t-This program initializes an array of user-defined size and\n\t-sorts it according to a specified algorithm.\n");
	
	//population of array
	printf("\n\t-How many elements would you like to sort?:\n");
	scanf("%d",&n);
	
	int array[n];
	srand(time(NULL));
	printf("\n\tUnsorted list is as follows:\n\t");
	for(i = 0; i <= n; i++){
		array[i] = rand() % 100;
		printf("%d  ", array[i]);
	}
	
	//sort generated array
	printf("\n\nNow calling the Bubble Sort function & displaying the steps...\n");
	bubbleSort(array, n);

	printf("\n\nNow calling the Selection Sort function & displaying the steps...\n");
	selectionSort(array, n);

	printf("\n\nNow calling the Insertion Sort function & displaying the steps...\n");
	insertionSort(array, n);
	
	//display sorted array
	printf("\n\n\n\tSorted list is as follows\n\t");
	
	for(i = 0; i <= n; i++){
		printf("%d ", array[i]);
	}
	
	return;
}