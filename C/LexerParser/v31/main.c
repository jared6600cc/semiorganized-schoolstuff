/******************************************
  Jared Bumgardner
  main.c
  Project 1
  Due 10Feb2023
 ******************************************/
 
 /* Pre-processor directives */
 #include <stddef.h>
 #include <stdio.h>
 #include <stdlib.h>
 
 /* This function... */
 void parse(FILE *inputFile){
	 
 }
 
 /* This function... */
 int main(int argc, char *argv[]){
	 // Declarations
	 FILE *inputFile;	// pointer to input file (as specified by cla)
	 
	 // Check number of command line arguments
	 if(argc != 2){
		 perror("\nERROR: Too few command line arguments\n");
		 exit(-1);
	 } else {
		 // Expected number of arguments found. Attempt opening input file.
		 inputFile = fopen(argv[1], "r");
		 if(inputFile == NULL){
			 perror("\nERROR: Cannot open input file ");
		 } else {
			 // File opened successfully. Parse input file.
			 printf("File opened successfully. TODO: Parse input file.");
			 parse(inputFile);		// refactor if needed. Just created a function to keep main clean
		 }
		 
		 // Cleanup
		 fclose(inputFile);
	 }
	 return 0;
 }