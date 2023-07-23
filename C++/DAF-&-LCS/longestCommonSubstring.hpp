/***************************************************************
  Jared Bumgardner
  longestCommonSubstring.hpp
  Project 5

  This file contains the declaration of the longestCommonSubstring class & it member function prototypes
***************************************************************/

#ifndef LONGESTCOMMONSUBSTRING_HPP
#define LONGESTCOMMONSUBSTRING_HPP

#include <vector>
#include <string>
using namespace std;

class lcs 
{
public:
	vector<vector<int>> L;			// Array used to calculate LCS & LCS length
	string string1, string2;		// The strings used to build the L table
	
	/***************************************************************
	lcs::buildTable()
	This function builds the objects L array used in determing LCS & LCS length.
	It uses O(m*n) space.
	***************************************************************/
	void buildTable();
	
	/***************************************************************
	lcs::buildTableReduced()
	This function finds the LCS length using two internal n sized arrays.
	It uses O(2*n) space. It is the space optimized version of lcs::buildTable()
	It returns the length of the LCS.
	***************************************************************/
	int buildTableReduced();

	/***************************************************************
	lcs::determineSimularity(int lengthLCS)
	This function finds the simularity between string1 & string2 using the measures given by Prof Coffey.
	It takes the length of the LCS as an argument.
	It returns a char that represents the degree of simularity. 'D': dissimilar, 'L': low, 'M': medium, 'H': high
	***************************************************************/
	char determineSimularity(int lengthLCS);

	/***************************************************************
	lcs::printLCS(int i, int j)
	This function prints the LCS using the values saved in the L table.
	It take two indices i & j as arguments to allow for recursive access to L.
	***************************************************************/
	void printLCS(int i, int j);
};

#endif