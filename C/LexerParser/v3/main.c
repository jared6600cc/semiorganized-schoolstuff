/***************************************************************
  Jared Bumgardner
  main.c
  Project 1

  Main file drives execution of Lexical Analyzer & Parser.
***************************************************************/
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	if(argc == 2){
		/* Expected # of command line args */
		// open input file
		FILE * fp = fopen(argv[1], "r");
		if(fp == NULL){
			/* File Open Failed */
			perror("ERROR: Failed to open input file\n");
			exit(-1);
		} else {
			/* File Opened */
			
		}
		fclose(fp);
	} else {
		/* Incorrect # of command line args */
		perror("ERROR: Incorrect number of command line arguments\n");
		exit(-1);
	}
	
	return 0;
}