//   Jared Bumgardner
//   COP 3530 - Prof. Mishra
//   Definition: The following program contains implementations for the following:
//				-Binary Search Tree
//				-Inorder and level traversal
//   11/23/2016

#include <stdio.h>
#include <stdlib.h>

//node
struct node {
	int data;
	int quantity;
	struct node *left;
	struct node *right;
	struct node *parent;
};

struct node *left(struct node *root){
	//return pointer to left subtree of root
	return root->left;
}

struct node *right(struct node *root){
	//return pointer to right subtree of root
	return root->right;
}

struct node *parent(struct node *root){
	//return pointer to partent of root
	return root->parent;
}

int info(struct node *root){
	//return information within node
	return root->data;
}

struct node *addLeft(struct node *root, int data){
	//create new node & initialize
	struct node *left = (struct node*)malloc(sizeof(struct node));
	left->data = data;
	left->parent = root;
	
	return left;
}

struct node *addRight(struct node *root, int data){
	//create new node & initialize
	struct node *right = (struct node*)malloc(sizeof(struct node));
	right->data = data;
	right->parent = root;
	
	return right;
}



//tree
struct tree {
	struct node *root;
};

void find(int key, struct tree *BST){
	//find node with given key
	struct node *current = BST->root;
	
	//look for key
	while(current->data != key){
		if(key < current->data)			//left
			current = current->left;
		else							//right
			current = current->right;
		
		if(current == NULL){			//no child
			printf("\nKey does not exist.");
			return;
		}
	}
	
	printf("\nKey exists.");
	return;
}

void insert(int data, struct tree *BST){

	//create node to be inserted
	struct node *insert = (struct node*)malloc(sizeof(struct node));
	insert->data = data;
	
	struct node *curr = (struct node*)malloc(sizeof(struct node));
	struct node *parent = (struct node*)malloc(sizeof(struct node));
	
	//insert
	if(!BST->root){			//root does not exist; insert as root
		BST->root = insert;
	}
	else{					//root exists; insert as leaf
		if(!curr){
			curr = BST->root;
		}

	while(1){
		parent = curr;
			if(data < curr->data){			//go left
			curr = curr->left;
			if(!curr){
				parent->left = insert;
				return;
			}
		}
			else{							//go right
				curr = curr->right;
				if(curr == NULL){
					parent->right = insert;
					return;
				}
			}
		}
	}
}

void inOrder(struct node *localRoot){
	if(localRoot != NULL){				//if current is not empty		
		if(!localRoot->left)
			inOrder(localRoot->left);				//left	
			
			printf("%d  ", localRoot->data);		//root		
		
		if(!localRoot->right)
			inOrder(localRoot->right);				//right
	}
	return;
}

void levelOrder(struct node *root){
	if(!root)
		return;
	
	
}

void main(){
	//declarations
	int numNodes = 0;		//number of user specified nodes
	int userData;			//data to be entered into new node
	int i;					//index for looping
	int userSearch;			//keeps track of user search choice
	int userInt;			//keeps track of user search key
	
	//introduction
	printf("\n\t***Binary Search Tree Implementation/Test***\n\t-Jared Bumgardner");
	printf("\n\n\t-This program reads in the number of nodes in a Binary Tree.");
	printf("\n\t-Then it reads the integer data values in the nodes and displays them inorder.");
	printf("\n\t-After that it asks you to try searching for a node data value.");
	printf("\n\t-It then simply informs you if or not the node is in the tree");
	
	printf("\n\nEnter the number of nodes in the tree: \n");
	scanf("%d", &numNodes);
	
	//create tree
	struct tree *BST = (struct tree*)malloc(sizeof(struct tree));
	BST->root = NULL;
	
	//populate tree
	for(i = 0; i < numNodes; i++){
		printf("\nEnter the data value: \n");
		scanf("%d", &userData);
		
		insert(userData , BST);
	}	
	
	//print tree inorder
	inOrder(BST->root);

	//print tree level order traversal
//	levelOrder(BST->root);


	do{
		//optional user search
		printf("\n\n(1): Search for existence of int\n(2): Exit\n");
		scanf("%d", &userSearch);
		
		//act according to input
		switch(userSearch){
			
			case 1 :
			//search for user's key
			printf("\nWhat integer would you like to determine the status of?\n");
			scanf("%d", &userInt);
			
//			find(userInt, BST);
			
			case 2 :
			//exit
			break;
		}
		
		//search again?
		printf("\n(1): Search for another\n(2): Exit");
		scanf("&d", &userSearch);
	}while(userSearch == 1);
	
	printf("\n***END***");
	return;
}