#include <iostream>
#include <vector>
#include <cstring>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "parse.hpp"



int main(int argc, char* argv[])
{
	// Declarations
	
	std::cout << "Welcome to myShell!" << std::endl;
	Parse p;
	
	// program loop
	bool programFinished = false;
	while (!programFinished)
	{
		// prompt
		std::cout << "$$ ";
		
		
		// parse input
		std::string userInput = "";
		std::getline(std::cin, userInput);
		
		
		// parse arguments from input
		std::vector<std::string> args = p.ParseArgs(userInput);
		
 	
		// parse input redirection command
 		std::string inputFile = p.ParseInputRedirect(userInput);
 		std::string outputFile = p.ParseOutputRedirect(userInput);
		
		Param param(inputFile, outputFile, args);
		
		
		// Execute command
		if(param.getArgumentCount() == 0)	// Skips execution attempt if empty string
		{
			continue;
		}
		
		if(atoi(args[1].c_str()) >= 2)		// Get number of processes to create
		{
			int numProccess = atoi(args[1].c_str());
			for(int i = 0; i < numProccess; i++)
			{
				pid_t childPID;
				childPID = fork();
				if(childPID == 0)
				{	// Child process code
					// run command & pass later arguments
//					std::vector<char*> argv(args.size() + 1);		// "Shell must generate a new arg vector for each process"
//					// TODO Copy any arguments for process 
//					execvp(args[0].c_str, args.data());
				}
				else if (childPID < 0)
				{	// Fork failed code
					std::cout << "fork failed" << std::endl; 
					return -1;
				} 
				else 
				{	// Parent code
					int returnStat;
					waitpid(childPID, &returnStat, 0);	//parent waits here
			
					if(returnStat == 0)
						std::cout << "return status: no error" << std::endl;
					if(returnStat == 1)
						std::cout << "return status: child process terminated with an error" << std::endl;
	
				}
			}
		}
		
		
		
		// Exit command entered?
		std::size_t exitFound = args[0].find("exit");
		if(exitFound != std::string::npos)
		{
			programFinished = true;
		}
		
		
		// Debug mode?
		if(argc >= 2)
			if(strcmp(argv[1], "-Debug") == 0)
			{
				std::cout << std::endl;
				std::cout << "Parameters: " << std::endl;
				param.PrintParams();
			}
	}
	
	return 0;
}
