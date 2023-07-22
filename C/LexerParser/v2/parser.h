/***************************************************************
  Jared Bumgardner
  parser.h
  Project 3

  Contains prototypes & declarations for the parser.
  Must implement a stack-based PDA.
***************************************************************/


#include <stdio.h>
#include <ctype.h>


/* This function will take a token from the lexical analyzer and 
 * parse it using a stack-based PDA. 
 */
int parse();