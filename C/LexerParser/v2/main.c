/***************************************************************
  Jared Bumgardner
  main.c
  Project 3

  Main file drives execution of program.
***************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "parser.h"


int main(int argc, char *argv[]){
	
	
	// Check command line arguments
	if(argc == 2){			/* (argc == 2) */
		FILE *inputFile;
		if((inputFile = fopen(argv[argc - 1], "r")) == NULL){
			/* FAILED to open input file.\n */
			perror("ERROR: Input file did not open.\n");
			exit(-1);
		} else {
			/* SUCCEEDED to open input file.\n */
			// Parse input file token by token
			int tok;		// token from lexical analyzer
			while((tok = lexan(inputFile)) != EOF){
				parse();
			}
		}
		fclose(inputFile);
	} else {				/* (argc > 2 || argc < 2) */
		perror("ERROR: Incorrect number of command line arguments.\n");
		exit(-1);
	}


	return 0;
}
