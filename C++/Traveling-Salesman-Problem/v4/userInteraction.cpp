/***************************************************************
  Jared Bumgardner
  userInteraction.cpp
  Project 3

  Other comments regarding the file - description of why it is there, etc.
***************************************************************/

#include "userInteraction.hpp"
using namespace std;



userInteraction::userInteraction()
{
}

bool userInteraction::isInt(std::string line)
{
    for (char const& c : line)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}

int userInteraction::getInt(std::string message)
{
    string inLine;
    do
    {
        cout << message;
        getline(cin, inLine);
        if (isInt(inLine))
        {
            return stoi(inLine, nullptr, 10);
        }
        else
        {
            cout << "ERROR: Enter a positive integer..." << endl;
        }
    } while (1);
}

parameters userInteraction::getUserInfo()
{
    parameters params;

    cout << "====================INPUT====================" << endl;
    string promptMessage = "Number of cities to run: ";
    params.numCities = getInt(promptMessage);
    while (params.numCities > 20 || params.numCities < 1)
    {
        cout << "ERROR: Enter a number between 1 and 20..." << endl;
        params.numCities = getInt(promptMessage);
    }

    promptMessage = "Number of tours in a generation: ";
    params.numTours = getInt(promptMessage);
    while (params.numTours < 1)
    {
        cout << "ERROR: Enter a positive number..." << endl;
        params.numTours = getInt(promptMessage);
    }

    promptMessage = "Number of generations: ";
    params.numGenerations = getInt(promptMessage);
    while (params.numGenerations < 1)
    {
        cout << "ERROR: Enter a positive number..." << endl;
        params.numGenerations = getInt(promptMessage);
    }

    promptMessage = "Percentage of a generation that is mutations: ";
    params.percentMutations = getInt(promptMessage);
    while (params.percentMutations < 1 || params.percentMutations > 100)
    {
        cout << "ERROR: Enter a number between 1 and 100..." << endl;
        params.percentMutations = getInt(promptMessage);
    }
    cout << "=============================================" << endl;

    return params;
}

void userInteraction::outputResults(parameters params, std::chrono::duration<double> bfaTime, std::chrono::duration<double> gaTime, double bfOptimalCost, double gaOptimalCost)
{
    cout << "============================OUTPUT============================";
    cout << endl << "Number of cities run: " << params.numCities;
    cout << endl << "Optimal cost from Brute Force: \t" << bfOptimalCost;
    if (bfaTime.count() > 1)
        cout << endl << "Time the Brute Force Algorithm took: \t" << bfaTime.count() << " seconds";
    else
        cout << endl << "Time the Brute Force Algorithm took: \t" << bfaTime.count() * 1000 << " miliseconds";

    cout << endl << "Cost from the Genetic Algorithm: \t" << gaOptimalCost;

    if (gaTime.count() > 1)
        cout << endl << "Time the Genetic Algorithm took: \t" << gaTime.count() << " seconds";
    else
        cout << endl << "Time the Genetic Algorithm took: \t" << gaTime.count() * 1000 << " miliseconds";

    cout << endl << "Percent of optimal that the Genetic Algorithm Produced: \t" << (gaOptimalCost/bfOptimalCost)*100 << "%";
    cout << endl << "==============================================================" << endl;
    return;
}

