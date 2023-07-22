/***************************************************************
  Jared Bumgardner
  lexer.h
  Project 3

  Contains prototypes & declarations for the symbol table and lexical analyzer.
***************************************************************/


#include <stdio.h>
#include <ctype.h>


// SYMBOL TABLE RESERVED WORDS
#define BEGIN 400
#define END 401
#define UNDERSCORE 402


// TOKEN TYPES
/* 
 * 0 = digit
 * 1 = alpha
 * 2 = else
 */ 


/* This function will take a pointer to a file, then read the file character by character
 * returning the type of symbol it is as an int. 
 */
int lexan(FILE *inputFile);