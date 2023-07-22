//study for exam2

#include<stdio.h>

int main(void){
	printf("\tFun With Strings");
	
	//declare character strings
	printf("\n\nCharacter string with explicitely & correctly stated size:");
	char word1[7] = {'H','E','L','L','O','!'};			//size explicitely & correctly stated
	printf("\v");
	printf(word1);
	
	printf("\n\nCharacter string with explicitely & incorrectly stated size:");
	char word2[6] = {'H','E','L','L','O','!'};			//size explicitely & incorrectly stated
	printf("\v");
	printf(word2);
	
	printf("\n\nCharacter string with no stated size:");
	char word3[] = {'H','E','L','L','O','!'};			//no size stated
	printf("\v");
	printf(word3);
	
	//change character string
	printf("\n\nWord1 change process:\n%s\n", word1);
	scanf("\n%s", word1);
	printf("changed to %s", word1);
	
	//repeat inputted string back to terminal
	printf("\n\nInput string to print: ");
	char string2print[10];
	scanf("%s", string2print);
	printf(string2print);
	
	return 0;
}