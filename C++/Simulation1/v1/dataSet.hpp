/***************************************************************
  Jared Bumgardner
  dataSet.hpp
  Project 4

  Contains class definition for dataSet class.
  This class handles data created based on given specifications.
  It contains the implementation of the Monte Carlo algorithm for analyzing.
***************************************************************/
#ifndef DATASET_H
#define DATASET_H

#include <vector>
#include <string>
#include <cmath>
#include "inputParameters.hpp"

class dataSet
{
public:
    // Meta data
    std::vector<std::string> batchFileNames;        // Names of all files holding data
    int totalBadSets = 0;                           // Total number of bad sets created
    int maxBadItems = 0;                            // Maximum number of bad items in a bad dataset
    int minBadItems = 0;                            // Minimum number of bad items in a bad dataset
    int totalBadItems = 0;                          // Total number of bad items in the dataset
    double avgBadItems = 0;                         // Average number of bad items per bad dataset

    void printMetaData();                                       // Print dataset/simulation data to console
    void cleanup(inputParameters inParams);                     // Delete all dataset files
    void analyze(dataSet data, inputParameters inParams);       // Analyze dataset using Monte Carlo algorithm
    dataSet(inputParameters inParams);                          // Constructor
};

#endif // DATASET_H