/***************************************************************
  Jared Bumgardner
  parser.h
  Project 1

  Contains prototypes & declarations for the Parser.
***************************************************************/
#include <errno.h>
#include <stdio.h>
#include "lexer.h"


typedef struct Parser Parser;
struct Parser{
	int tmp;
	int valid;
};


void match(int t);


void setLookahead(FILE *inputFile);


void parse(char token);