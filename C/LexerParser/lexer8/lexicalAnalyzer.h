/******************************************************************************
  Jared Bumgardner
  lexicalAnalyzer.h
  Project 1

  Provides prototypes for lexical analysis.
******************************************************************************/
#ifndef LEXICALANALYZER_H
#define LEXICALANALYZER_H

#include <stdio.h>

void exitWithError(int errorLineNo, char * errorMessage);
void parse();
int lexan();

#endif // LEXICALANALYZER_H
