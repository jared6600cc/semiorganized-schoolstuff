/***************************************************************
  Jared Bumgardner
  adjacencyMatrix.cpp
  Project 3

  Other comments regarding the file - description of why it is there, etc.
***************************************************************/

#include "adjacencyMatrix.hpp"
using namespace std;

adjacencyMatrix::adjacencyMatrix()
{
    // Initialize matrix
    vector < vector <double> > tmp(MATRIXWIDTH, std::vector<double>(MATRIXWIDTH));
    matrix = tmp;

    // Initialize lastAdded
    vector<int> tmp2;
    tmp2.push_back(0);
    tmp2.push_back(0);
}

void adjacencyMatrix::build(std::queue<double> inData)
{
    for (int y = 0; y < MATRIXWIDTH; y++)
    {
        for (int x = 0; x < MATRIXWIDTH; x++)
        {
            if (x == y)  // On diagonal 
            {
                matrix[x][y] = 0;
            }
            else
            {
                matrix[x][y] = inData.front();
                matrix[y][x] = matrix[x][y];
                inData.pop();
            }
        }
    }
}

void adjacencyMatrix::print()
{
    for (int y = 0; y < MATRIXWIDTH; y++)
    {
        for (int x = 0; x < MATRIXWIDTH; x++)
        {
            cout << setw(8) << matrix[x][y];
        }
        cout << endl;
    }
}

adjacencyMatrix adjacencyMatrix::readDistancesFile()
{
    ifstream inDistancesFile;       // File
    string inLine;                  // File Line Buffer
    queue<double> inDistancesData;  // File Data Buffer
    adjacencyMatrix cities;         // Cities Graph

    inDistancesFile.open("distances.txt");
    if (inDistancesFile.is_open()) // Input file opened
    {
        while (getline(inDistancesFile, inLine))
        {
            inDistancesData.push(stod(inLine));
        }
        cities.build(inDistancesData);
        //        cities.print();                                   // DEBUG
        inDistancesFile.close();
    }
    else                       // Input file did not open
    {
        cout << "ERROR: Cannot open distances.txt\n";
        exit(-1);
    }
    return cities;
}
