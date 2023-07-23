/***************************************************************
  Jared Bumgardner
  dataSet.cpp
  Project 4

  This file implements the dataSet class defined in dataSet.hpp
***************************************************************/
#include "dataSet.hpp"
using namespace std;



// Print dataset/simulation data to console
void dataSet::printMetaData()
{
    cout << "\t\tTotal bad sets = " << totalBadSets << endl;
    cout << "\t\tMax number of bad items in a bad set = " << maxBadItems << endl;
    cout << "\t\tMin number of bad items in a bad set = " << minBadItems << endl;
    cout << "\t\tAverage number of bad items in a bad set = " << avgBadItems << endl;
    cout << endl;
}



// Delete all dataset files
void dataSet::cleanup(inputParameters inParams)
{
    // For every batch of items
    for (auto s : batchFileNames)
    {
        // Delete the file
        if (remove(s.c_str()) != 0)
        {
            cout << "ERROR DELETING DATA SET FILE" << endl;
        }
    }
}



// Analyze dataset using Monte Carlo algorithm
void dataSet::analyze(dataSet data, inputParameters inParams)
{
    // For every batch of items
    int badBatchesFound = 0;
    for (auto i : data.batchFileNames)
    {
        ifstream inFile(i);
        if (inFile)
        {
            // Sample the appropriate number of items
            string inLine;
            bool isBadBatch = false;
            for (int j = 0; j < inParams.sampleSize; j++)
            {
                getline(inFile, inLine);
                if (inLine.compare("b") == 0)
                {
                    // Bad batch has been found!
                    badBatchesFound++;
                    break;
                }
            }
        }
        else
        {
            // File containing batch of items did not open!
            cout << "ERROR OPENING DATASET FILE" << endl;
            exit(-1);
        }
    }
    // Report analytics
    double base = (100 - (double)inParams.percentBadItems) * .01;
    double exponent = inParams.sampleSize;
    cout << "\t\tTotal bad sets found = " << badBatchesFound << endl;
    cout << "\t\tPercentage of bad batches actually detected = " << ((double)badBatchesFound/(double)totalBadSets)*100 << "%" << endl;
    cout << "\t\tBase = " << base << " exponent = " << exponent << endl;
    cout << "\t\tPredicted P(failure to detect bad batch) = " << pow(base, exponent) << endl << endl;
}



// Constructor
dataSet::dataSet(inputParameters inParams)
{
    // For each batch of items
    minBadItems = inParams.numItemsPerBatch;
    for (int i = 1; i <= inParams.numBatches; i++)
    {
        // Construct file name
        string batchName = "ds";
        batchName.append(to_string(i));
        batchName.append(".txt");

        // Decide if bad batch
        bool badBatch = false;
        if (i <= ((inParams.percentBadBatches *.01) * inParams.numBatches))
            badBatch = true;

        // Construct file contents
        ofstream outFile(batchName);
        if (badBatch)
        {
            int currentBadItems = 0;
            totalBadSets++;
            // Populate bad batch
            srand((unsigned)time(0));
            for (int j = 0; j < inParams.numItemsPerBatch; j++)
            {
                if ((rand() % 99) < inParams.percentBadItems)
                {
                    outFile << "b\n";
                    currentBadItems++;
                }
                else
                {
                    outFile << "g\n";
                }
            }
            //Update dataset metadata
            if (currentBadItems > maxBadItems)
                maxBadItems = currentBadItems;
            if (currentBadItems < minBadItems)
                minBadItems = currentBadItems;
            totalBadItems += currentBadItems;
            avgBadItems = (double)totalBadItems / (double)totalBadSets;
        }
        else
        {
            // Populate good batch
            for (int j = 0; j < inParams.numItemsPerBatch; j++)
            {
                outFile << "g\n";
            }
        }
        batchFileNames.push_back(batchName);
        outFile.close();
    }
    printMetaData();
}