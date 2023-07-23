/***************************************************************
  Jared Bumgardner
  main.c
  Project 2

  Main file drives execution of Lexical Analyzer & Parser.
  Provided programs are converted to register code & evaluated.
***************************************************************/
#include "parser.h"

/* Main: expects exactly 1 command line argument (name of file to parse) */
int main(int argc, char *argv[]){
 	if(argc == 2){
		/* Expected # of command line args */
		fp = fopen(argv[1], "r");
		if(fp == NULL){
			// File failed to open
			perror("ERROR: Failed to open input file\n");
			exit(-1);
		} else {
			// File opened successfully
			printf("\n\nCompiling %s\n", argv[1]);
			process();
			printf("Success\n");
		}
		fclose(fp);
	} else {
		/* Incorrect # of command line args */
		perror("ERROR: Incorrect number of command line arguments\n");
		exit(-1);
	}
	return 0;
}
