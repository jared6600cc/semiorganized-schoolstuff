//   Jared Bumgardner
//   COP 3530 - Prof. Mishra
//   Definition: The following program contains implementations for the following:
//				-Linked List definitions and functions
//				-Queue operations
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




//queue associated pointers
int queueNum = 0;




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
	
	//declarations
	int i;

	//save the first node's data
	int deleteMe = head->data;
	
	//make head point past node being deleted
	head = head->next;
	
	//return deleted value
	return deleteMe;
}

int deleteLast(){
	
	//declarations
	int i;
	
	//set index to start of list
	struct node* curr = head;
	struct node* temp1;
	
	do{
		temp1 = curr;
		curr = curr->next;
		
		if(curr->next == NULL){
			temp1->next = NULL;
		}
		
	}while(temp1->next != NULL);
	
	return curr->data;
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



//queue functions
void enqueue(int data){
	
	printf("Enqueueing: %d", data);
	
	//add data into queue
	insertFirst(data);
	queueNum++;
	
	return;
}

int dequeue(){
	
	int dequeueThis = NULL;
	
	//remove data from end of queue
	if(queueNum > 1)
		dequeueThis = deleteLast();
	else{
		dequeueThis = head->data;
		head->next = NULL;
	}
	
	queueNum--;
	printf("Dequeueing: %d", dequeueThis);
	
	return dequeueThis;
}

void display(){
	
	//display queue
	displayList();
	
	return;
}

int isEmpty(){
	
	//determine if queue is empty
	if(queueNum == 0)
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
	printf("\n\t***QUEUE TEST***");
	printf("\n\t---This program implements a queue using a linked list");
	printf("\n\t---An ENQUEUE operation adds elements to the queue and\n\t---a DEQUEUE operation removes elements from the queue.");
	
	do{
		//get user input
		printf("\n\n\t---What do you want to do? Enter: 1 to ENQUEUE, 2 to DEQUEUE, 3 to DISPLAY, 4 to QUIT: ");
		scanf("%userChoice", &userChoice);
		
		//act according to user input
		switch(userChoice){
			
			case 1 :
				//enqueue
				printf("\nInput element to enqueue: ");
				scanf("%userInput", &userInput);
				enqueue(userInput);
				break;
			
			case 2 :
				//dequeue
				dequeue();
				break;
			
			case 3 :
				//display
				display();
				break;
				
			case 4 :
				//quit
				break;
				
		}
		
	}while(userChoice != 4);
	
	return;
}