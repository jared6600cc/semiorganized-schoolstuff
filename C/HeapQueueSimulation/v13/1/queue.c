

#include<stdlib.h>
#include<stdio.h>













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