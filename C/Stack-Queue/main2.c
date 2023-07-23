//   Jared Bumgardner
//   COP 3530 - Prof. Mishra
//   Definition: V1
//   *Date*

#include<stdlib.h>

//linked list structure & associated pointer
typedef struct nodes{
	int data;
	struct node *next;

} Node;

Node *head = NULL;
Node *curr = NULL;

void createNode(int data);
void insertFirst();
void deleteFirst();
void displayList();
void push();
void pop();
void displayStack();
void isStackEmpty();
void enqueue();
void dequeue();
void displayQueue();
void isQueueEmpty();

//main
void main(){
	
	//creation of linked list's extra labels
	head = malloc(sizeof(Node));
	head->data = 1;
	head->next = malloc(sizeof(Node));
	head->next = NULL;
	
	curr = malloc(sizeof(Node));
	curr->data = 1;
	curr->next = NULL;
	
	createNode(5);
	
	return;
}

//linked list
void createNode(int data){
	
	//create new node
	Node *temp;
	temp = (Node*)malloc(sizeof(Node));
	temp->next = malloc(sizeof(Node));
	
	temp->data = data;
	temp->next = &head;	//=Head;
	
	if(head->next == NULL){
//		head.next = temp;
		}
	
}

void insertFirst(){
	//linked list
}

void deleteFirst(){
	//linked list
}

void displayList(){
	//linked list
}


//stack
void push(){
	//stack
}

void pop(){
	//stack
}

void displayStack(){
	//stack
}

void isStackEmpty(){
	//stack
}


//queue
void enqueue(){
	//queue
}

void dequeue(){
	//queue
}

void displayQueue(){
	//queue
}

void isQueueEmpty(){
	//queue
}
