/***************************************************************
  Jared Bumgardner
  parser.h
  Project 2

  Contains recursive descent parsing function prototypes.
  Also contains stack prototypes.
***************************************************************/
#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include "symTable.h"

FILE * fp;			// program specified by command line argument

//CharStack
#define STACKMAX 256
int top;
char charStackPeek();
void charStackPush(char newC);
char charStackPop();
int charStackIsEmpty();
void charStackPrint();
void charStackInit(int size);

//Parser
void infixToPostfix();
void exitWithError(int errorLineNo, char * errorMessage);
void match(int given);
void assignStmt();
void expr();
void term();
void factor();
void intDecls();
void intDeclaration();
void parse();
void process();
int lexan();

#endif // PARSER_H
