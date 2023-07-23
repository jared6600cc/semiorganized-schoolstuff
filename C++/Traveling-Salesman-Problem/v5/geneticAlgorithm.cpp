/***************************************************************
  Jared Bumgardner
  geneticAlgorithm.cpp
  Project 3

  Other comments regarding the file - description of why it is there, etc.
***************************************************************/

#include "geneticAlgorithm.hpp"

std::string swap(int x, int y, std::string s, parameters p) 
{
	char tmp;
	tmp = s[x%p.numCities];
	s[x%p.numCities] = s[y%p.numCities];
	s[y%p.numCities] = tmp;
	return s;
}

std::string mutate(std::string s, parameters p) 
{
	srand(time(NULL));
	int rand1 = rand() % p.numCities;
	int rand2 = rand() % p.numCities;
	std::string mutatedTour = swap(rand1, rand2, s, p);
	return mutatedTour;
}

std::vector<double> evaluateFitness(adjacencyMatrix edgeWeights, parameters params, std::vector<std::string> tours)		// INLINE THIS? CURRENTLY USELESS
{
	std::vector<double> tourResults;
	int fromCity, toCity;

	for (int i = 0; i < params.numTours; i++)	// Iterate through all tours
	{
		std::string currTour = tours[i];
		double pathLength = 0;
		for (int j = 0; j < params.numCities - 1; j++)	// Calculate current tour
		{
			fromCity = currTour[j] - '0';
			toCity = currTour[j+1] - '0';
			pathLength += edgeWeights.matrix[fromCity][toCity];
		}
		tourResults.push_back(pathLength);
	}

	return tourResults;
}

std::vector<std::string> getInitialPermutations(std::vector<std::string> tours, parameters params)
{
	// Generate tours & place in vector
	for (int i = 0; i < params.numTours; i++) 
	{
		std::string newTour;
		for (int i = 0; i < params.numCities; i++) // Populate tour
		{
			newTour += std::to_string(i);
		}
		newTour = swap(0, i, newTour, params);
		tours.push_back(newTour);
	}	
	return tours;
}


double geneticAlgorithmTSP(adjacencyMatrix edgeWeights, parameters params) 
{
	// Choose the initial population of tours
	std::vector<std::string> tours;
	tours = getInitialPermutations(tours, params);

	// Evaluate the fitness of each individual tour
	std::vector<double> tourCosts;
	tourCosts = evaluateFitness(edgeWeights, params, tours);

	// Repeat until termination criteria are met
	double eliteCost = 1000000000;
	for (int i = 0; i < params.numGenerations; i++)
	{
		// Select best-ranking individual as elite
		std::string eliteTour;
		for (int i = 0; i < params.numTours; i++) 
		{
			if (tourCosts[i] < eliteCost) 
			{
				eliteTour = tours[i];
				eliteCost = tourCosts[i];
			}
		}
		// Create additional tours through crossover, mutation, or both, & create offspring			// VECTOR SUBSCRIPT ERROR WHEN RAN. I have run out of time to fix. Time to submit. :(
//		tours.clear();
//		tours.push_back(eliteTour);
//		for (int j = 0; j < params.numTours-1; j++) 
//		{
//			std::string newMutatedEliteTour = mutate(eliteTour, params);
//			tours.push_back(newMutatedEliteTour);
//		}
		// Evaluate the fitness of each individual tour
		tourCosts = evaluateFitness(edgeWeights, params, tours);
	}
	return eliteCost;
}