/***************************************************************
  Jared Bumgardner
  directAccessFile.hpp
  Project 5

  This file contains the declaration of the directAccessFile class & it member function prototypes
***************************************************************/

#ifndef DIRECTACCESSFILE_HPP
#define DIRECTACCESSFILE_HPP

#include <fstream>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class directAccessFile
{
private:
    ifstream fp;                    // file pointer to opened file
    vector<int> linePositions;      // indices for all lines in opened file 

public:
    int numStrings;                 // number of strings in file

    /***************************************************************
    directAccessFile::findLinePositions()
    This function reads the file until EOF & finds the offset for each line.
    ***************************************************************/
    void findLinePositions();

    /***************************************************************
    directAccessFile::getLineAtIndex(int index)
    This function seeks into the file to find the line with index provided as argument.
    It returns the desired line as a string.
    ***************************************************************/
    string getLineAtIndex(int index);

    /***************************************************************
    directAccessFile::directAccessFile(string openMe)
    This constructor opens the file provided as argument 'openMe'.
    ***************************************************************/
    directAccessFile(string openMe);

    /***************************************************************
    directAccessFile::close()
    This function safely closes the file that fp points to.
    ***************************************************************/
    void close();
};

#endif