/***************************************************************
  Jared Bumgardner
  lexer.c
  Project 3

  Implements the lexical analyzer.
***************************************************************/


#include "lexer.h"


// Number of lines in the file
int lineno = 0;


/* This function will take a pointer to a file, then read the file character by character
 * returning the type of symbol it is as an int. 
 */
int lexan(FILE *inputFile){
	char c;
	while((c = fgetc(inputFile)) != EOF){
		if(c == ' ' || c == '\t'){
			// Space or Tab
			;
		}
		else if(c == '\n' || c == '\r'){
			// Newline
			lineno++;
		}
		else if(c == '~'){
			// Comment
			while((c = fgetc(inputFile)) != '\n'){
				;
			}
			lineno++;
			continue;
		}
		else if(isdigit(c) > 0){
			// Digit
			return 0;
		}
		else if(isalpha(c) > 0){
			// Letter
			return 1;
		}
		else{
			// Something else...
			return 2;
		}
	}
	return EOF;
}