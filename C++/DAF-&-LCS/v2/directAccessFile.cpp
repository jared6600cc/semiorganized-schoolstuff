/***************************************************************
  Jared Bumgardner
  directAccessFile.cpp
  Project 5

  This file contains the implementations of the directAccessFile class member functions
***************************************************************/

#include "directAccessFile.hpp"

/***************************************************************
directAccessFile::findLinePositions()
This function reads the file until EOF & finds the offset for each line.
***************************************************************/
void directAccessFile::findLinePositions() 
{
    // Get number of strings
    string inLine;
    getline(fp, inLine);
    numStrings = stoi(inLine);

    // Get line positions
    char inByte, lastByte = '\n';
    int numBytes = 0;
    while (fp.get(inByte)) 
    {
        numBytes++;
        if (lastByte == '\n') 
        {
            linePositions.push_back(numBytes+1);
        }
        lastByte = inByte;
    }
}

/***************************************************************
directAccessFile::getLineAtIndex(int index)
This function seeks into the file to find the line with index provided as argument.
It returns the desired line as a string.
***************************************************************/
string directAccessFile::getLineAtIndex(int index) 
{
    string inLine;
    fp.clear();     // Clear EOF flag
    fp.seekg(linePositions[index] + 1);
    getline(fp, inLine);

    return inLine;
}

/***************************************************************
directAccessFile::directAccessFile(string openMe)
This constructor opens the file provided as argument 'openMe'.
***************************************************************/
directAccessFile::directAccessFile(string openMe)
{
    fp.open(openMe);
    if (fp)
    {
        findLinePositions();
    }
    else
        exit(-1);
}

/***************************************************************
directAccessFile::close()
This function safely closes the file that fp points to.
***************************************************************/
void directAccessFile::close() { fp.close(); }