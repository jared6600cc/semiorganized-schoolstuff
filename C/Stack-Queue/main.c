//   Jared Bumgardner
//   COP 3530 - Prof. Mishra
//   Definition: The following program contains implementations for the following:
//				-Linked List definitions and functions
//				-Stack operations
//				-Test code in main to test the implemented functions
//   10/31/2016

#include<stdlib.h>
#include<stdio.h>



//linked list structure & associated pointers
struct node {
	int data;
	struct node *next;
};

struct node *head = NULL;
struct node *curr = NULL;




//stack associated pointers
int stackNum = 0;




//linked list functions
void insertFirst(int data){
	
	//create new node
	struct node *new = (struct node*)malloc(sizeof(struct node));
	
	//initialize node information
	new->data = data;
	new->next = head;
	
	//update head ptr
	head = new;
	
	return;
}

int deleteFirst(){

	//save the first node's data
	int deleteMe = head->data;
	
	//make head point past node being deleted
	head = head->next;
	
	//return deleted value
	return deleteMe;
}

void displayList(){

	//set index at start of list
	struct node *index = head;
	
	//index through list & print info about nodes
	while(index != NULL){
		printf("\n%p\t%d", &index->data, index->data);
		index = index->next;
	}
	
	return;
}



//stack functions
void push(int data){
	
	printf("Pushing: %d", data);
	
	//push data onto top of stack
	insertFirst(data);
	stackNum++;
	
	return;
}

int pop(){

	int popThis = NULL;
	
	//remove data from top of stack
	if(stackNum != 0){
		popThis = deleteFirst();
		stackNum--;
		
		printf("\nPopping: %d", popThis);
	}
	else{
		printf("\nUnable to POP: Stack empty");
	}
	
	return popThis;
}

void display(){
	
	//displayStack
	displayList();
	
	return;
}

int isStackEmpty(){
	
	//determine if stack is empty
	if(stackNum == 0)
		return 0;
	else
		return 1;
}



//main
void main(){
	//declarations
	int userChoice = NULL;
	int userInput = NULL;
	
	//test
	printf("\n\t***STACK TEST***");
	printf("\n\t---This program implements a stack using a linked list");
	printf("\n\t---A PUSH operation adds elements to the stack and\n\t---a POP operation removes elements from the stack.");
	
	do{
		//get user input
		printf("\n\n\t---What do you want to do? Enter: 1 to PUSH, 2 to POP, 3 to DISPLAY, or 4 to QUIT: ");
		scanf("%userChoice", &userChoice);
		
		//act according to user input
		switch(userChoice){
			
			case 1 :
				//push node
				printf("\n\tEnter the integer element to PUSH: ");
				scanf("%userInput", &userInput);
				push(userInput);
				
				break;
			
			case 2 :
				//pop node
				pop(userInput);
				
				break;
			
			case 3 :
				//display node
				display();
				break;
			
			case 4 :
				//quit
				break;
		}
		
	}while(userChoice != 4);
	
	return;
}