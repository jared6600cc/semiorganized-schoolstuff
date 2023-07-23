/***************************************************************
  Jared Bumgardner
  LCS.cpp
  Project 5

  This file contains the main function & drives program execution
***************************************************************/

#include <iomanip>
#include "longestCommonSubstring.hpp"
#include "directAccessFile.hpp"
using namespace std;


int main()
{
    // PART 1
    cout << "PART 1: " << endl;
    string inLine;
    ifstream inFileTS("twoStrings.txt");
    if (inFileTS) 
    {
        lcs l;
        // Read input file (twoStrings.txt)
        getline(inFileTS, inLine);
        l.string1 = inLine;
        getline(inFileTS, inLine);
        l.string2 = inLine;

        // Build LCS table
        l.buildTable();

        // Display strings & LCS
        cout << "String 1: " << endl << l.string1 << endl << endl;
        cout << "String 2: " << endl << l.string2 << endl << endl;
        cout << "LCS: ";
        l.printLCS(l.string1.length(), l.string2.length());
    }
    else 
    { 
        cout << "ERROR: Cannot open twoStrings.txt"; 
    }
    inFileTS.close();


    // PART 2
    cout << endl << endl << "PART 2: ";

    // Setup direct access file
    directAccessFile inFileMS("multiStrings.txt");
    
    // Setup simularity table
    vector<vector<string>> simularityTable;
    simularityTable.resize(inFileMS.numStrings + 1, vector<string>(inFileMS.numStrings + 1));
    simularityTable[0][0] = "";
    for (int i = 1; i < inFileMS.numStrings + 1; i++)
    {
        simularityTable[0][i] = to_string(i);
        simularityTable[i][0] = to_string(i);
    }
    
    // Calculate simularity table
    lcs l2;
    int lengthLCS = 0;
    for (int i = 1; i < inFileMS.numStrings + 1; i++)
    {
        for (int j = 1; j < inFileMS.numStrings + 1; j++)
        {
            if (i + 1 < j + 1) 
            {
                l2.string1 = inFileMS.getLineAtIndex(i - 1);
                l2.string2 = inFileMS.getLineAtIndex(j - 1);
                lengthLCS = l2.buildTableReduced();
                simularityTable[i][j] = l2.determineSimularity(lengthLCS);
            }
            else 
            {
                simularityTable[i][j] = "-";
            }
        }
    }

    // Print simularity table
    cout << endl;
    for (int i = 0; i < inFileMS.numStrings + 1; i++)
    {
        for (int j = 0; j < inFileMS.numStrings + 1; j++)
        {
            cout << left << setw(2) << setfill(' ') << simularityTable[i][j] << " ";
        }
        cout << endl;
    }


    // Cleanup
    inFileMS.close();
}