/***************************************************************
  Jared Bumgardner
  parser.c
  Project 1

  Implements the Parser.
***************************************************************/
#include "parser.h"


int lookahead;		// holds the next token


void match(int t){
	if(lookahead == t)
		;//lookahead = lexan(inputFile);
	else
		;//perror("syntax error");
}


void setLookahead(FILE *inputFile){
	lookahead = lexan(inputFile);
}


void parse(char token){
	// Check for consecutive underscores
	// Check identifier for hanging underscore

	
}