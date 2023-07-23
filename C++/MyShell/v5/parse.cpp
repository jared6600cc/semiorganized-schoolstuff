#include "parse.hpp"
#include <cstring>


// constructors
Param::Param()
{
	inputRedirect = "";
	outputRedirect = "";
	argumentCount = 0;
}



Param::Param(std::string inputFile, std::string outputFile, std::vector<std::string> argList)
{
	inputRedirect = inputFile;
	outputRedirect = outputFile;
	argumentCount = 0;
	SetArgumentVector(argList);
}



// ---- PUBLIC ----
void Param::PrintParams()
{
	// copied from project description
	std::cout << "InputRedirect: [" << ((inputRedirect != "") ? inputRedirect : "NULL") << "]" << std::endl << 
		"OutputRedirect: [" << ((outputRedirect != "") ? outputRedirect : "NULL") << "]" << std::endl << "ArgumentCount: [" << argumentCount << "]" << std::endl;
	
	
	for (int i = 0; i < argumentCount; i++)
		std::cout << "ArgumentVector[" << i << "]: [" << argumentVector[i] << "]" << std::endl;
}



// setters
void Param::SetInputRedirect(std::string newInput)
{
	this->inputRedirect = newInput;
}



void Param::SetOutputRedirect(std::string newOutput)
{
	this->outputRedirect = newOutput;
}



void Param::SetArgumentVector(std::vector<std::string> newArgs)
{
	// FIXME: type mismatch
	//this->argumentVector = newArgs;
	this->argumentCount = newArgs.size();

	for (int i=0; i < argumentCount; ++i)
	{
		argumentVector[i] = newArgs.at(i);
	}
}


// getters
int Param::getArgumentCount()
{
	return argumentCount;
}

// constructor
Parse::Parse()
{
	
}



// ---- PUBLIC ----
std::vector<std::string> Parse::ParseArgs(std::string strToParse)
{
	// declarations
	std::vector<std::string> args;
	std::string inputFileName = "";
	std::string outputFileName = "";
	
	// exit if empty string
	if(strToParse.empty())
		return args;
	
	// get first token & initialize return vector
	const char* c_string = strToParse.c_str();
	char* token = strtok((char*)c_string, " ");
	int currTokens = 0;
	args.push_back(token);
	
	// get all tokens
	while(token)
	{			
		// get next token
		token = strtok(NULL, " ");
		if(token != NULL)
		{
			args.push_back(token);
			currTokens++;
		}
	}
		
	return args;
}



std::string Parse::ParseInputRedirect(std::string strToParse)
{
	// declarations
	std::vector<std::string> args;
	std::string inputFile = "";
	
	// get first token
	const char* c_string = strToParse.c_str();
	char* token = strtok((char*)c_string, " ");
	int currTokens = 0;
	args.push_back(token);
	
	// get all tokens
	while(token)
	{
		//check token for output redirect
		if(strchr(token, '<') != NULL)
		{
			inputFile = token;
		}
		
		// get next token
		token = strtok(NULL, " ");
		if(token != NULL)
		{
			args.push_back(token);
			currTokens++;
		}
	}
	
	return inputFile;

}



std::string Parse::ParseOutputRedirect(std::string strToParse)
{
	// declarations
	std::vector<std::string> args;
	std::string outputFile = "";
	
	// get first token
	const char* c_string = strToParse.c_str();
	char* token = strtok((char*)c_string, " ");
	int currTokens = 0;
	args.push_back(token);
	
	// get all tokens
	while(token)
	{
		//check token for output redirect
		if(strchr(token, '>') != NULL)
		{
			outputFile = token;
		}
		
		// get next token
		token = strtok(NULL, " ");
		if(token != NULL)
		{
			args.push_back(token);
			currTokens++;
		}
	}
	
	return outputFile;

}
