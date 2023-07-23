/***************************************************************
  Jared Bumgardner
  .c
  Project 1

  .
***************************************************************/
#include "parseTree.h"

void parseTreeOpenBracket(){
    /* Add a new node as left child of current node, descent to the left child */
    currNode->leftC = create();
    currNode = currNode->leftC;
}

void parseTreeCloseBracket(){
    /* Go to the parent of the current node */
    currNode = currNode->parent;
}

void parseTreeTerminal(char * currToken){
    /* Set the root value of the current node & return to parent */
    printf("terminal is assmtstm: %s\n", currToken);        // debug
    currNode->value = currToken;
    currNode = currNode->parent;
}

void parseTreeOperator(char currToken){
    /* Set the root value of the current node, add a new node as right child of the current node. Then descent to child. */
    printf("operator in assmtstm: %c\n", currToken);        //debug
    currNode->value = &currToken;
    currNode->rightC = create();
    currNode = currNode->rightC;
}

void postOrderPrint(struct node* root){
    printf("statement to parenthesize: %s", unparenthesizedStmt);
//    if(root == NULL){return;}
//    postOrderPrint(root->leftC);
//    postOrderPrint(root->rightC);
//    printf("%s, ", root->value);
}

void initParseTree(){
    currNode = create();
    memset(unparenthesizedStmt, 0, strlen(unparenthesizedStmt));
    strcat(unparenthesizedStmt, "");
}

struct node* create(){
    struct node* newN = malloc(sizeof(struct node));
    return newN;
}

struct node* insertLeft(struct node* root, char * inValue){
    root->leftC = create();
    root->leftC->parent = root;
    root->leftC->value = inValue;
    return root->leftC;
}

struct node* insertRight(struct node* root, char * inValue){
    root->rightC = create();
    root->rightC->parent = root;
    root->rightC->value = inValue;
    return root->rightC;
}

