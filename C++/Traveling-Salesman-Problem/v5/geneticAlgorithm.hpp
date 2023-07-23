/***************************************************************
  Jared Bumgardner
  geneticAlgorithm.hpp
  Project 3

  Other comments regarding the file - description of why it is there, etc.
***************************************************************/

#ifndef GENETICALGORITHM_HPP
#define GENETICALGORITHM_HPP

#include <vector>
#include <cstdlib>
#include <time.h>
#include "userInteraction.hpp"
#include "adjacencyMatrix.hpp"

std::string swap(int x, int y, std::string s, parameters p);
std::string mutate(std::string s, parameters p);
std::vector<double> evaluateFitness(adjacencyMatrix edgeWeights, parameters params, std::vector<std::string> tours);
std::vector<std::string> getInitialPermutations(std::vector<std::string> tours, parameters params);
double geneticAlgorithmTSP(adjacencyMatrix edgeWeights, parameters params);

#endif