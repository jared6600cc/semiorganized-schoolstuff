/***************************************************************
  Jared Bumgardner
  inputParameters.hpp
  Project 4

  Contains class definition for inputParameters class.
  This class handles obtaining data from provided input files.
***************************************************************/
#ifndef INPUTPARAMETERS_H
#define INPUTPARAMETERS_H



#include <string>
#include <iostream>
#include <fstream>



class inputParameters
{
private:
    void build(std::string inName);     // Builds object from file

public:
    int numBatches = 0;                 // Number of batches of items
    int numItemsPerBatch = 0;           // Number of items in each batch
    int percentBadBatches = 0;          // Percentage of batches containing bad items
    int percentBadItems = 0;            // Percentage of items that are bad in a bad batch
    int sampleSize = 0;                 // Items sampled from each batch

    void print();                           // Print parameters to console
    inputParameters(std::string inName);    // Constructor
};



#endif // INPUTPARAMETERS_H