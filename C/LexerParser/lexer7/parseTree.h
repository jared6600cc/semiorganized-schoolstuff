/***************************************************************
  Jared Bumgardner
  .h
  Project 1


***************************************************************/
#ifndef PARSETREE_H
#define PARSETREE_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct node * currNode;
char * result;
char unparenthesizedStmt[256];

struct node{
    char * value;
    struct node * parent;
    struct node * leftC;
    struct node * rightC;
};

void parseTreeOpenBracket();
void parseTreeCloseBracket();
void parseTreeTerminal(char * currToken);
void parseTreeOperator(char currToken);
void postOrderPrint();
void initParseTree();

struct node* create();
struct node* insertLeft(struct node* root, char * inValue);
struct node* insertRight(struct node* root, char * inValue);


#endif // PARSETREE_H
