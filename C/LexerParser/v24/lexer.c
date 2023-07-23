#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
#include "lexer.h"



int lexan(char *inputFile){		// RECURSIVE DESCENT PARSER
	FILE *f;		// input file pointer
	char ch = '.';
	
	// Open input file
	f = fopen(inputFile, "r"); 
	if(f == NULL){
		perror("ERROR: Can not open input file");
	} else {
		// File opened successfully
		// Read file by character
		while((ch = fgetc(f)) != EOF){
			// if ch is a space or ch is a tab then do nothing
			if(ch == ' '){						// Is space?						w
				printf("*space found!*\n");
			} else if(ch == '\t'){				// Is tab?
				printf("*tab found!*\n");
			}
			else if(ch == '\n' || ch == '\r'){				// Is newline?			w
				printf("*newline found!*\n");
			}
			// else if ch is a tilde
			else if(ch == '~'){					// Is tilde? Is comment?			w
				printf("*tilde found!*\n");
			}
			else if(isdigit(ch) > 0){			// Is digit?						w
				printf("*digit found!*\n");
			}
			else if(isalpha(ch) > 0){			// Is letter?						w
				printf("*letter found!*\n");
			}
			else if(ch == EOF){					// EOF?
				printf("*EOF found!*\n");
			}
			else
				return ch;
		}
	}
	
	fclose(f);
	return ch;		// todo : MOVE ME? Only putting here to shut up compiler
}

void match(int t){		// RECURSIVE DESCENT PARSER
	//if lookahead==t
		//lookahead= lexan();
	//else
		//error("syntax error")
	return;
}

void factor(){		// RECURSIVE DESCENT PARSER
	//if(lookahead == ID)
		//match(ID);
	//else if lookahead == NUM
		//match(NUM);
	//else if lookahead == '('
		// match('(');
		// expression;
		// match(')');
	// else
		// error
	return;
}

void term(){		// RECURSIVE DESCENT PARSER
	//factor
	//while(lookahead = '*' or lookahead = '/')
		//match(lookahead);
		//factor;
	return;
}

void expression(){		// RECURSIVE DESCENT PARSER
	//term;
	//while(lookahead = '+' or lookahead = '-')
		//begin
		//   match(lookahead);
		//   term;
		//end
	return;
}

void assignStmt(){		// RECURSIVE DESCENT PARSER
	//match(ID)
	//if(lookahead <> '=') then error
	// else begin
	//    match(lookahead);
	//    expression;
	//    match(';');
	// end
	return;
}