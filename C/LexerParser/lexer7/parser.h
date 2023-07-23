/***************************************************************
  Jared Bumgardner
  parser.h
  Project 1

  Contains recursive descent parsing function prototypes.
***************************************************************/
#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include "symTable.h"

FILE * fp;			// program specified by command line argument

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
