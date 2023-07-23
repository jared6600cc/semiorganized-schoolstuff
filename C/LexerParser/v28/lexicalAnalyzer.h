/***************************************************************
  Jared Bumgardner
  lexicalAnalyzer.h
  Project 1

  Contains data and function prototypes for lexical analysis.
***************************************************************/
#ifndef LAHEADER
#define LAHEADER

#include <stdio.h>
#include "parser.h"

FILE * fp;          // Program specified by command line argument
int lookahead;      // Next token from lexical analyzer

int lexan();
void parse();

#endif // LAHEADER
