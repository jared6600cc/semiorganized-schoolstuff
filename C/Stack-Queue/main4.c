/* Jared Bumgardner
 * Implementation of Double Linked List structure,
 * associated functions, and main.
 */
 
 #include<stdlib.h>
 #include<stdio.h>
 
 //define Double Linked List node structure
 struct nodeDLL {
	 int num;
	 struct nodeDLL* nextPTR;
	 struct nodeDLL* previousPTR;
	 };
 
 struct nodeDLL* headPTR = NULL;	//global variable pointer to head of dll
 
 //implementation of double linked list and functions 
 void deleteNode(struct nodeDLL *delete){
	 
	 //adjust node pointers 
	 if(delete == headPTR){
		 headPTR = delete->nextPTR;
	 }
	 else{
		 delete->nextPTR->previousPTR = delete->previousPTR;
		 
	 }
	 
	 //free allocated space to node
	 free(delete);
	 
	 return;
 }
 
 void displayNodes(){
	 //declarations
	 int j = 0;
	 struct nodeDLL* curr = headPTR;
	 
	 //print node information
	 printf("Printing Nodes... ");
	 
	 while(curr != NULL){
		 printf("\nNode%i: \t%d \t%p", j, curr->num, (void*)&curr);
		 curr = curr->nextPTR;
		 
		 j++;
	 }
	 
	 printf("\n");
	 free(curr);		//free allocated space
	 
	 return;
 }
 
 struct nodeDLL * createNode(int data){
	 //create node (first in double linked list)
	 struct nodeDLL* createdNode = (struct nodeDLL*)malloc(sizeof(struct nodeDLL));
	 
	 //adjust node data & pointers
	 if(headPTR == NULL){
		 headPTR = createdNode;
	 }
	 
	 createdNode->num = data;
	 createdNode->nextPTR = NULL;
	 createdNode->previousPTR = NULL;
	 
	 return createdNode;
 }
 
 void insertFirst(struct nodeDLL *list, int data){
	 
	 //create new node with given data
	 struct nodeDLL* insertNode = createNode(data);

	 //adjust node pointers
	 if(headPTR == NULL){
		 headPTR = insertNode;
	 }
	 else{
		 insertNode->previousPTR = headPTR;
		 insertNode->nextPTR = headPTR->nextPTR;
		 headPTR->nextPTR = insertNode;
	 }
	 
	 return;
 }
 
 void insertAfter(struct nodeDLL *afterThis, int data){
	 //create new node with given data
	 struct nodeDLL* insertNode = createNode(data);
	 
	 //adjust node pointers
	 insertNode->previousPTR = afterThis;
	 insertNode->nextPTR = afterThis->nextPTR;
	 afterThis->nextPTR = insertNode;
	 
	 return;
 }
 
 void insertEnd(int data){
	 //declarations
	 struct nodeDLL* endPTR = headPTR;
	 
	 //create new node with given data
	 struct nodeDLL* insertNode = createNode(data);
	 
	 //go to end
	 while(endPTR->nextPTR != NULL){
		 endPTR = endPTR->nextPTR;
	 }
	 
	 endPTR->nextPTR = insertNode;
	 insertNode->previousPTR = endPTR;
	 insertNode->num = data;

 }
 
 struct nodeDLL * findInsert(int key){
	 //declarations
	 int j = 0;
	 struct nodeDLL* curr = headPTR;
	 
	 //search for key
	 while(curr != NULL){
		 if(curr->num < key)
			 insertAfter(curr, key);
		 curr = curr->nextPTR;
		 
		 j++;
	 }
 }
 
 void main(){
	 //declarations
	 int i, temp, tempCase, numNodes = 0;
	 int userChoice = -1;
	 
	 //introduce program & get node info from user
	 printf("\n\n\n\n\n\t***Linked List Demo***\n\t-Jared Bumgardner\n");
	 printf("\n\t-Please enter the number of nodes that you would like to create: ");
	 scanf("%i", &numNodes);
	 
	 for(i = 0; i < numNodes;i++){
		 printf("\tEnter (ascending) Data for Node #%i: ", i+1);
		 scanf(" %d", &temp);
		 
		 if(i == 0)
			 headPTR = createNode(temp);
		 else
			 insertEnd(temp);
	 }
	 
	 printf("\n\n\t*Data gathering for nodes completed...\n");
	 
	 //display linked list data & node addresses
	 printf("\n\n");
	 displayNodes();
	 
	 do{
		 //get user input and act accordingly
		 printf("\n\nOptions:\nAdd a node (1)\tDelete a node (2)\tDisplay Nodes (3)\tQuit (4)\n");
		 scanf(" %userChoice", &userChoice);
		 
		 switch(userChoice){
			 
			 case 1 :
				//add a node
				printf("\n\n**Add a node**\nValue to add: ");
				scanf(" %i", &tempCase);
				findInsert(tempCase);
				break;
			 
			 case 2 :
				//delete a node
				printf("\n\n**Delete a node**\nNode index to delete: ");
				scanf(" %i", &tempCase);
				break;
			 
			 case 3 :
				//display nodes
				displayNodes();
				break;
			 
			 case 4 :
				//quit
				break;
		 }
		 
	 }while(userChoice != 4);
 }