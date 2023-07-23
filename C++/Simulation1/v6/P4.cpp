/***************************************************************
  Jared Bumgardner
  P4.cpp
  Project 4

  Contains main function.
***************************************************************/
#include "inputParameters.hpp"
#include "dataSet.hpp"

using namespace std;

int main()
{
    // Initialize parameter files to test
    vector<string> inputFileNames = { "t1.txt", "t2.txt", "t3.txt", "t4.txt" };

    // For each input file...
    int simulationIndex = 1;
    for (auto i : inputFileNames) 
    {
        cout << endl << "Simulation " << simulationIndex << ":" << endl;   // Show simulation header

        // Read parameters from file
        inputParameters inParams(i);
        inParams.print();

        // Generate data set
        cout << "\tGenerating data sets" << endl;
        dataSet data(inParams);

        // Analyze data sets / mc algorithm
        cout << "\tAnalyzing data sets" << endl;
        data.analyze(data, inParams);

        // Delete data sets
        data.cleanup(inParams);

        simulationIndex++;
    }
    cout << "\a";       // Beeeeeeeep
    return 0;
}