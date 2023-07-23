#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h> 
#include <string.h> 
#include <errno.h>
#include "lexer.h"


int lookahead;		// holds the next token


int main(int argc, char *argv[]){
	// Declarations
	int i;			// looping index
	
	/* Process command line argments */
	system("clear");											// clear the terminal
	if(argc < 2){	// Too few command line arguments?
		perror("\nERROR: Too few command line arguments\n");
		exit(-1);
	} else {		// Enough command line arguments.
		/* Open each input files */
		printf("*Opening input files*\n");
		for(i = 0; i < (argc - 1); i++){
			/* Parse each input file */
			printf("\n*Parsing input file (%s)*\n", argv[i+1]);
			
			
			
			lexan(argv[i+1]);
			
			
			
			
			
			
		}
	}



	printf("\a");		/* "its like a reward" */
	return 0;
}