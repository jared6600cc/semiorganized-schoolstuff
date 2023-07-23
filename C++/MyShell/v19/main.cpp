// Jared Bumgardner
// Systems & Networks 1
// Project 1
// 29 Sept. 2019

#include <iostream>
#include <fstream>
#include <string.h>
#include "myshell.hpp"

using namespace std;

int main(int argc, char *argv[]){
	//Declarations
	char* line = NULL;		// var: user input & commands
	size_t len = 0;			// var: size of the user input
	int exitFlag = 0;		// var: state of the shell: 0 = go; 1 = stop
	Param shell;			// var: Shell execution object
	
	//Display prompt, get user input, process user input
	while(!exitFlag){
		//Prompt & get user input
		cout << "$ ";
		getline(&line, &len, stdin);
		
		//Tokenize into parameters object
		int i = 0;
		char* tok = strtok(line, " ");
		while(tok != NULL){
			shell.setArgumentVector(tok, i);
			if(strstr(tok, "<") != 0){
				tok = strtok(NULL, " ");
				shell.setInputRedirect(tok);
			} else {
				tok = strtok(NULL, " ");
			}
			shell.setArgumentCount(i);
			i++;
		}
		
		//Print parameters object
		if((argv[1] != NULL) && (strcmp(argv[1], "-Debug") == 0)){
			cout << "Printing Parameters...\n";
			shell.printParams(shell);
		}
		
		if(strcmp(line, "exit\n") == 0)	//Is exit command?
			break;
	}
	return 0;
}//end

