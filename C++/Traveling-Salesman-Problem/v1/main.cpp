/*
 * Jared Bumgardner
 * COP4534
 * Prof. Coffey
 * 11:59pm 3 November 2019
 */



#include "bfTSP.hpp"
#include "gaTSP.hpp"
#include "globals.hpp"

#include <iostream>
#include <ctime>
#include <cstdio>
#include <fstream>

using namespace std;



int main(){
	// Read input file
	ifstream inFile;
	double inFileData;				//Buffer for data read from input file
	inFile.open("distances.txt");
	if(!inFile){
		cout << "Input file not found...\n...exiting...\n";
		return(1);
	}
	
	double distances[MAXCITIES][MAXCITIES];		//Holds distance data from input file
	int i = 0;					//Line counter 1
	int j = 1;					//Line counter 2
	
	for(i = 0; i < MAXCITIES; i++){//Initialize adjacency matrix
		distances[i][i] = 0;
	}
	
	for(i = 0; i < MAXCITIES; i++){//Populate adjacency matrix
		for(j = i+1; j < MAXCITIES; j++){
			inFile >> inFileData;
			distances[i][j] = inFileData;
//			cout << "distances[" << i << "][" << j << "]: " << distances[i][j] << "\n";	//DEBUG
			distances[j][i] = inFileData;
//			cout << "distances[" << j << "][" << i << "]: " << distances[j][i] << "\n";	//DEBUG
		}
	}
	inFile.close();
	
	
	
	// Get user input
	cout << "\n\t*USER INPUT*\n";
	cout << "Number of cities: ";
	int numCities;
	cin >> numCities;
	cout << "Tours in a generation: ";
	int numTours;
	cin >> numTours;
	cout << "Number of generations: ";
	int numGenerations;
	cin >> numGenerations;
	cout << "% of a generation that is mutant: ";
	double mutantPercent;
	cin >> mutantPercent;
	
	
	
	// Setup timers
	std::clock_t start;
	double bfTime;
	double gaTime;
	
	
	
	// BRUTE FORCE ALGORITHM
	cout << "\n\tBF ALGORITHM\n";
	start = std::clock();
	bfTSP(distances, numCities);
	bfTime = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	
	
	
	// GENETIC ALGORITHM
	cout << "\n\tGA ALGORITHM\n";
	start = std::clock();
	gaTSP();
	gaTime = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	
	
	
	// Display final output
	cout << "\n";
	cout << "\n\t***OUTPUT***\n";
	cout << "number of cities: " << numCities << "\n";
	cout << "optimal cost from brute force: " << "\n";
	cout << "brute force alg time: " << bfTime << "\n";
	cout << "ga alg cost: " << "\n";
	cout << "ga alg time: " << gaTime << "\n";
	cout << "percent of optimal from ga alg: " << "\n";
	cout << "\n";
	
	return 0;
}
