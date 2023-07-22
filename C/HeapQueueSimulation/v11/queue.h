#ifndef queue
#define queue


struct node{
		int data;
		struct Customer *cust;
		struct node *next;
		};

//Function prototypes
int enqueue(struct node * add);
int dequeue();
int isEmpty();
  
#endif
