/***************************************************************
  Jared Bumgardner
  inputParameters.cpp
  Project 4

  This file implements the inputParameters class defined in inputParameters.hpp
***************************************************************/
#include "inputParameters.hpp"
using namespace std;



// Build contents of object from input file
void inputParameters::build(std::string inName) 
{
    string inLine;
    ifstream inFile(inName);
    if (inFile.is_open())
    {
        getline(inFile, inLine);
        numBatches = stoi(inLine);
        getline(inFile, inLine);
        numItemsPerBatch = stoi(inLine);
        getline(inFile, inLine);
        percentBadBatches = stoi(inLine);
        getline(inFile, inLine);
        percentBadItems = stoi(inLine);
        getline(inFile, inLine);
        sampleSize = stoi(inLine);
        inFile.close();
    }
    else
    {
        cout << "ERROR OPENING INPUT FILE" << endl;
        exit(-1);
    }
}



// Print contents of object to console
void inputParameters::print() 
{
    cout << "\tNumber of batches of items: " << numBatches << endl;
    cout << "\tNumber of items in each batch: " << numItemsPerBatch << endl;
    cout << "\tPercentage of batches containing bad items: " << percentBadBatches << endl;
    cout << "\tPercentage of items that are bad in a bad set: " << percentBadItems << endl;
    cout << "\tItems sampled from each set: " << sampleSize << endl;
    cout << endl;
}



// Constructor
inputParameters::inputParameters(std::string inName) 
{
    build(inName);
}