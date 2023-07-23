/***************************************************************
  Jared Bumgardner
  userInteraction.hpp
  Project 3

  Other comments regarding the file - description of why it is there, etc.
***************************************************************/


#ifndef USERINTERACTION_HPP
#define USERINTERACTION_HPP

#include <string>
#include <chrono>
#include <iostream>


struct parameters
{
	int numCities;
	int numTours;
	int numGenerations;
	int percentMutations;
};

class userInteraction 
{
public:
	userInteraction();
	bool isInt(std::string line);
	int getInt(std::string message);
	parameters getUserInfo();
	void outputResults(parameters params, std::chrono::duration<double> bfaTime, std::chrono::duration<double> gaTime, double bfOptimalCost, double gaOptimalCost);
};

#endif