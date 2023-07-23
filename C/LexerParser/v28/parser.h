/***************************************************************
  Jared Bumgardner
  parser.h
  Project 1

  Contains recursive descent parsing function prototypes.
***************************************************************/
#ifndef PARSERHEADER
#define PARSERHEADER

#include "symTable.h"
#include "lexicalAnalyzer.h"

int lineno;     // Line number counter

void exitWithError(int errorLineNo, char * errorMessage);
void match(int given);
void assignStmt();
void expr();
void term();
void factor();

#endif // PARSERHEADER
