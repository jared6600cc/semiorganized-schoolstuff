#ifndef queue2
#define queue2
	//queue structure
	struct node{
		int data;
		struct node *next;
		};
		
	struct node *head = NULL;
	struct node *curr = NULL;
	
	int queueNum = 0;
  
  //function prototypes
  int enqueue();
  int dequeue();
  int isEmpty();
  
#endif
