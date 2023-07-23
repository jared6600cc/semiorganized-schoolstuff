/***************************************************************
  Jared Bumgardner
  lexer.h
  Project 1

  Contains prototypes & declarations for the Lexical Analyzer.
***************************************************************/
#include <errno.h>
#include <stdio.h>


void createSymbolTable(int STSIZE);	


int lexan(FILE *inputFile);
