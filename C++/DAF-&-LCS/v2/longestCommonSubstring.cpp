/***************************************************************
  Jared Bumgardner
  longestCommonSubstring.cpp
  Project 5

  This file contains the implementations of the longestCommonSubstring class member functions
***************************************************************/

#include "longestCommonSubstring.hpp"
#include <iostream>


/***************************************************************
lcs::buildTable()
This function builds the objects L array used in determing LCS & LCS length.
It uses O(m*n) space.
***************************************************************/
void lcs::buildTable()
{
    L.clear();
    int m = string1.length() + 1;   // vertical iterator bound
    int n = string2.length() + 1;   // horizontal iterator bound
    L.resize(m, vector<int>(n));

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (string1[i - 1] == string2[j - 1])
            {
                L[i][j] = L[i - 1][j - 1] + 1;      // Diagonal
            }
            else
            {
                if (L[i - 1][j] >= L[i][j - 1])     // Left & Up
                {
                    L[i][j] = L[i - 1][j];          // Up
                }
                else
                {
                    L[i][j] = L[i][j - 1];          // Left
                }
            }
        }
    }
}

/***************************************************************
lcs::buildTableReduced()
This function finds the LCS length using two internal n sized arrays.
It uses O(2*n) space. It is the space optimized version of lcs::buildTable()
It returns the length of the LCS.
***************************************************************/
int lcs::buildTableReduced()
{
    L.clear();
    int m = string1.length() + 1;
    int n = string2.length() + 1;
    vector<int> current, previous;
    current.resize(n);
    previous.resize(n);

    for (int i = 1; i < m; i++) 
    {
        previous = current;
        for (int j = 1; j < n; j++) 
        {
            if (string1[i - 1] == string2[j - 1])
            {
                current[j] = previous[j - 1] + 1;   // Diagonal
            }
            else 
            {
                if (previous[j] >= current[j - 1]) // Left & Up
                {
                    current[j] = previous[j];   // Up
                }
                else 
                {
                    current[j] = current[j - 1];    // Left
                }
            }
        }
    }
    
    return current[n - 1];
}

/***************************************************************
lcs::determineSimularity(int lengthLCS)
This function finds the simularity between string1 & string2 using the measures given by Prof Coffey.
It takes the length of the LCS as an argument.
It returns a char that represents the degree of simularity. 'D': dissimilar, 'L': low, 'M': medium, 'H': high
***************************************************************/
char lcs::determineSimularity(int lengthLCS)
{
    char simularity = 'D';
    string longerString, shorterString;

    if (string1.length() > string2.length()) 
    {
        longerString = string1;
        shorterString = string2;
    }
    else 
    {
        longerString = string2;
        shorterString = string1;
    }

    // Is High simularity?
    if (shorterString.length() >= (longerString.length() - (longerString.length() * .1)))
    {
        if ((shorterString.length() * .9) <= lengthLCS)
        {
            simularity = 'H';
            return simularity;
        }
    }
    if (shorterString.length() >= (longerString.length() - (longerString.length() * .2)))
    {
        // Is Medium simularity?
        if ((shorterString.length() * .8) <= lengthLCS)
        {
            simularity = 'M';
            return simularity;
        }
    }
    if (shorterString.length() >= (longerString.length() - (longerString.length() * .4)))
    {
        // Is Low simularity?
        if ((shorterString.length() * .5) <= lengthLCS) 
        {
            simularity = 'L';
            return simularity;
        }
    }

    return simularity;
}

/***************************************************************
lcs::printLCS(int i, int j)
This function prints the LCS using the values saved in the L table.
It take two indices i & j as arguments to allow for recursive access to L.
***************************************************************/
void lcs::printLCS(int i, int j)
{
    if (i == 0 || j == 0)     // CHECK FOR OUT OF BOUNDS
        return;
    if (string1[i] == string2[j]) // MOVE DIAGONALLY
    {
        printLCS(i - 1, j - 1);
        cout << string1[i];
    }
    else if (L[i - 1][j] >= L[i][j - 1]) // MOVE UP
    {
        printLCS(i - 1, j);
    }
    else // MOVE LEFT
    {
        printLCS(i, j - 1);
    }
}
