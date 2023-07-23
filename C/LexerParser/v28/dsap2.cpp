/***************************************************************
  Jared Bumgardner
  dsap2.cpp
  Project 2

  This file contains the main execution function for the program. (incomplete)
***************************************************************/


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "analytics.hpp"
#include "simulation.hpp"


using namespace std;


int main()
{
    // Declarations
    string inLine;      // file line buffer
    ifstream inTest;   //  test name buffer


    // Define & prepare tests
    vector<vector<string>> tests;   // holds all test data
    vector<string> test1, test2;    // individual tests' data
    test1.push_back("test1.txt");
    test2.push_back("test2.txt");
    tests.push_back(test1);
    tests.push_back(test2);

    for (size_t i = 0; i < tests.size(); i++)  // read test parameters from input files
    {
        inTest.open(tests[i][0], ios::in);
        if (inTest.is_open()) 
        {
			cout << "Test #" << i+1 << " Parameters:" << endl;
            while (getline(inTest, inLine)) 
            {
                tests[i].push_back(inLine);
                cout << inLine << endl;
            }
			cout << endl;
        }
        else // error opening test's input file
        {
            return -1;
        }
        inTest.close();
    }


    // Run simulations based on provided parameters
    for (size_t i = 0; i < tests.size(); i++) 
    {
        analytics results;
        simulation s;
        s.simulate(tests[0]);
		cout << endl << "Simulation #" << i << " Results:";
        results.print();
    }

    return 0;
}