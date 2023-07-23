#include <iostream>
#include <string>
#include <vector>



class Parse
{
	private:
		
		
	public:
		Parse();
		
		std::vector<std::string> ParseArgs(std::string strToParse);
		std::string ParseInputRedirect(std::string strToParse);
		std::string ParseOutputRedirect(std::string strToParse);
};



/* don’t test program with more than this many tokens for input */
#define MAXARGS 32
#include <string>
#include <vector>
#include <iostream>



/* class to hold input data */
/* feel free to add missing constructor, destructors, and getter/setter functions */
/* instead of char * you may also use the string class */
class Param
{
	private:
		std::string inputRedirect; /* file name or "" */
		std::string outputRedirect; /* file name or "" */
		int argumentCount; /* number of tokens in argument vector */
		std::string argumentVector[MAXARGS]; /* array of strings */
	public:
		Param();
		Param(std::string inputFile, std::string outputFile, std::vector<std::string> argList);
		
		void SetInputRedirect(std::string newInput);
		void SetOutputRedirect(std::string newOutput);
		void SetArgumentVector(std::vector<std::string> newArgs);
		
		int getArgumentCount();
		
		void PrintParams();
};
