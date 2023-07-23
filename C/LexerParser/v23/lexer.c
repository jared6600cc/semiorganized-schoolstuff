/***************************************************************
  Jared Bumgardner
  lexer.c
  Project 1

  Implements the Lexical Analyzer.
***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
#include "lexer.h"
#include "symbolTable.h"


FILE *inputFile;
int lineno = 1;
HashTable * st;


void createSymbolTable(int STSIZE){		// Create the symbol table
	st = createTable(STSIZE);
}


int lexan(FILE *f){		// RECURSIVE DESCENT 
	char ch;
	inputFile = f;
	// update lookahead using ungetc or similar
	// File opened successfully
	// Read file by character
	while((ch = fgetc(inputFile)) != EOF){
		// if ch is a space or ch is a tab then do nothing
		if(ch == ' ' || ch == '\t')						// Is space or tab?		w
			;
		else if(ch == '\n' || ch == '\r'){				// Is newline?			w
			lineno++;
		}
		// else if ch is a tilde
		else if(ch == '~'){					// Is tilde? Is comment?			w
			while((ch = fgetc(inputFile)) != '\n'){
				;
			}
			lineno++;
			continue;
		}
		else if(isdigit(ch) > 0){			// Is digit?						w
			return (ch - '0');
		}
		else if(isalpha(ch) > 0){			// Is letter?						w
			if(lookup(st, &ch) == NULL){
				int index = hashFunc(&ch);
				char indexString[12];
				sprintf(indexString, "%d", index);
				insert(st, indexString, &ch);
			}
			return ch;
		}
		else				// Its something else?
			return ch;
	}
	return EOF;
}