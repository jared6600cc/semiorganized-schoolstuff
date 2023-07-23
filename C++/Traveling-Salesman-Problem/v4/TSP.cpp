/***************************************************************
  Jared Bumgardner
  TSP.cpp
  Project 3

  Other comments regarding the file - description of why it is there, etc.
***************************************************************/



#include <fstream>
#include <iomanip>
#include <vector>
#include <queue>
#include "bruteForce.hpp"
#include "geneticAlgorithm.hpp"
using namespace std;



int main()
{
    // Read distances.txt into 20x20 adjacency matrix
    adjacencyMatrix adjMatrix;
    adjMatrix = adjMatrix.readDistancesFile();


    // Get info from user
    userInteraction user;
    parameters params;
    params = user.getUserInfo();


    // Solve TSP by Brute Force Alg.
    double bfOptimalCost = 0;
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    bfOptimalCost = bruteForceTSP(adjMatrix, params);
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
    chrono::duration<double> bfDuration = chrono::duration_cast<chrono::duration<double>>(end - start);


    // Solve TSP by Gen. Alg.
    double gaOptimalCost = 0;
    start = std::chrono::high_resolution_clock::now();
    gaOptimalCost = geneticAlgorithmTSP(adjMatrix, params);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> gaDuration = end - start;
    

    // Output results to Console
    user.outputResults(params, bfDuration, gaDuration, bfOptimalCost, gaOptimalCost);


    // Pause for user to read results
    cout << endl << endl;
    system("pause");
    return 0;
}