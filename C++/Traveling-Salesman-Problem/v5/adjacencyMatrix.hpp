/***************************************************************
  Jared Bumgardner
  adjacencyMatrix.hpp
  Project 3

  Other comments regarding the file - description of why it is there, etc.
***************************************************************/

#ifndef ADJACENCYMATRIX_HPP
#define ADJACENCYMATRIX_HPP

#include <vector>
#include <queue>
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>

#define MATRIXWIDTH 20

class adjacencyMatrix
{
public:
    std::vector < std::vector <double> > matrix;
    adjacencyMatrix();
    adjacencyMatrix readDistancesFile();
    void build(std::queue<double> inData);
    void print();
};

#endif