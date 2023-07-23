// Jared Bumgardner
// Systems & Networks 1
//Project 1
// 29 Sept. 2019

#ifndef MYSHELL
#define MYSHELL

	#include <iostream>
	#include <string.h>
	using namespace std;
	

	#define MAXARGS 32	//Maximum accepted arguments for class Param
	class Param{
		private: 
			char *inputRedirect;			//
			char *outputRedirect;			//
			int background;				//
			int argumentCount;			//
			char *argumentVector[MAXARGS];		//
		public:
			//Public methods
			void printParams(Param shell){
				if(shell.getInputRedirect() == NULL)
					setInputRedirect((char*)"");
				cout << "InputRedirect: [" << inputRedirect << "]\n";
				cout << "OutputRedirect: [" << "]\n";
				
				cout << "Background: [" << "]\n";
				cout << "ArgumentCount: [" << argumentCount << "]\n";
				
				cout << "\n";
			}
			//Setters
			void setArgumentCount(int i){
				argumentCount = i;
			}
			void setArgumentVector(char *i, int j){
				argumentVector[j] = i;
			}
			void setInputRedirect(char *i){
				inputRedirect = i;
			}
			//Getters
			char* getArgumentVector(int i){
				return argumentVector[i];
			}
			int getArgumentCount(){
				return argumentCount;
			}
			char* getInputRedirect(){
				return inputRedirect;
			}
	};

	void func1();
#endif
