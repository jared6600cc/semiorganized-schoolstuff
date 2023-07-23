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
#include "lexicalAnalyzer.h"

FILE * fp;          // Program specified by command line argument
int lineno;         // Line number counter
int lookahead;      // Next token from lexical analyzer

void match(int given);
void assignStmt();
void expr();
void term();
void factor();

#endif // PARSER_H
