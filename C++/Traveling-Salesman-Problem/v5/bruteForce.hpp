/***************************************************************
  Jared Bumgardner
  bruteForce.hpp
  Project 3

  Other comments regarding the file - description of why it is there, etc.
***************************************************************/

#ifndef BRUTEFORCE_HPP
#define BRUTEFORCE_HPP

#include "userInteraction.hpp"
#include "adjacencyMatrix.hpp"

void printS(int* s, int numElements);
double perm1(int permsThisCall, int* s, int sSize, adjacencyMatrix citiesGraph);
double bruteForceTSP(adjacencyMatrix citiesGraph, parameters params);

#endif