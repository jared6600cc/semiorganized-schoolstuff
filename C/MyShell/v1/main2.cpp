#include <iostream>
#include <vector>
#include "parse.hpp"
#include "param.hpp"


int main()
{
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

		std::cout << "arguments: \n"; // for testing if arguments were parsed properly
		for (int i=0; i < args.size() ;++i)
		{
			std::cout << args.at(i) << std::endl;
		}

		// parse input redirection command
		std::string inputFile = p.ParseInputRedirect(userInput);
		std::cout << "inputRedirect: \n" << inputFile << std::endl;

		std::string outputFile = p.ParseOutputRedirect(userInput);
		std::cout << "outputRedirect: \n" << outputFile <<  std::endl;

		// create parameter object
		Param param(inputFile, outputFile, args);
		param.PrintParams();

		programFinished = true; // for testing purposes, program ends after single prompt/input
	}
}
