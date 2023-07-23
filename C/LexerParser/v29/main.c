/***************************************************************
  Jared Bumgardner
  main.c
  Project 1

  Main file drives execution of Lexical Analyzer & Parser.
***************************************************************/
#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h> 
#include <string.h> 
#include <errno.h>
#include "lexer.h"
#include "parser.h"
#include "symbolTable.h"


#define STSIZE 999999


int main(int argc, char *argv[]){
	// Declarations
	int i;			// looping index
	char tok;		// holds token from lexical analyzer
	FILE *f;		// input file pointer
	
	
	/* Process command line argments */
	system("clear");											// clear the terminal
	if(argc < 2 || argc > 2){	// Too few command line arguments?
		perror("\nERROR: Too few command line arguments\n");
		exit(-1);
	} else {		// Enough command line arguments.
		/* Open input file */
		for(i = 0; i < (argc - 1); i++){
			printf("*Opening input file (%s)*\n", argv[i+1]);
			f = fopen(argv[i+1], "r"); 
			if(f == NULL){
				perror("ERROR: Cannot open input file");
			} else {				
				// Parse input file
				Parser p;
				p.valid = 1;
				createSymbolTable(STSIZE);
				setLookahead(f);
				while((tok = lexan(f)) != EOF){
					parse(tok);
				}
				
				// Is program legal?
				printf("The program is legal: ");
				if(p.valid == 1)
					printf("success\n");
				else
					printf("failute\n");
				
				// Are there any error messages?
				
				
				// If not, report all identifers used (print symtbale)
				printSymbolTable();
				
			}
			fclose(f);
		}
	}
	return 0;
}