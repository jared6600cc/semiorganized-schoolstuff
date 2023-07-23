/*
 * Jared Bumgardner
 * 31 Oct. 2020
 * DS&A2
 * Proj. 3
 * Main.cpp :
 */



 #include <iostream>
 #include <fstream>
 #include <chrono>
 #include <bits/stdc++.h>

 #define AMSIZE 20		// Given size of adjacency matrix (nxn)
 double ADJACENCYMATRIX[AMSIZE][AMSIZE];

 void bf(int numCities){
	 // Setup path
	 int path[numCities+1];
	 for(int i = 0; i < numCities; i++){
		 path[i] = i;
	 }
	 path[numCities] = 0;

	 // Find all permutations of tour & evaluate each
	 double pathCost, bestPathCost = 0;
	 do{
		// Evaluate Tour
		 for(int j = 0; j < numCities+1; j++){
			 pathCost =+ ADJACENCYMATRIX[path[j]][path[j+1]];
			 
			 if(pathCost > bestPathCost)
               bestPathCost = pathCost;
		 }
		 std::cout << "pathCost = " << pathCost << std::endl;		// debug
	 } while (std::next_permutation(path, path + numCities));
 }


 void ga(){std::cout << "GENETIC ALGORITHM ENTERED" << std::endl;}


 /* **MAIN** */
int main(int argc, char* argv[]){
	// Get user inputs
	std::string userInput = "";
	int numCities, numToursGen, numGen, percGenMut;
	std::cout << std::endl << "==================== INPUT ====================" << std::endl;
	// --- number of cities to run
	std::cout << "Number of cities: " << std::endl;
	std::getline(std::cin, userInput);
	numCities = stoi(userInput);

	// --- number of individual tours in a given generation
	std::cout << "Number of individual tours per generation: " << std::endl;
	std::getline(std::cin, userInput);
	numToursGen = stoi(userInput);

	// --- number of generations to run
	std::cout << "Number of generations: " << std::endl;
	std::getline(std::cin, userInput);
	numGen = stoi(userInput);

	// --- % of a generation comprised of mutations
	std::cout << "% of mutations per generation: " << std::endl;
	std::getline(std::cin, userInput);
	percGenMut = stoi(userInput);
	std::cout << "===============================================" << std::endl;



	// Read input file(s)
	std::string line;
	std::ifstream distancesFile("distances.txt");
	// --setup graph
	if(distancesFile){
		int x = 0;
		int y = 0;
		while(std::getline(distancesFile, line)){
			if(x == y){
				ADJACENCYMATRIX[x][y] = 0;
				x = 0;
				y++;
			} else {
				ADJACENCYMATRIX[x][y] = std::stod(line);
				ADJACENCYMATRIX[y][x] = std::stod(line);
				x++;
			}
		}	
	}


	// Run brute force algorithm
	int bfOptimalCost;
	auto bfStart = std::chrono::high_resolution_clock::now();
	bf(numCities);
	auto bfTime = std::chrono::high_resolution_clock::now() - bfStart;

	// Run genetic algorithm
	int gaCost, gaOptimalCost;
	auto gaStart = std::chrono::high_resolution_clock::now();
	ga();
	auto gaTime = std::chrono::high_resolution_clock::now() - gaStart;



	// Display Output
	std::cout << std::endl << "========== OUTPUT ==========" << std::endl;
	//    n = num of cities run
	std::cout << "n = " << numCities << std::endl;
	//    brute force optimal cost
	std::cout << "BF Optimal Cost = " << bfOptimalCost << std::endl;
	//    brute force time
	long long bfMicrosecondTime = std::chrono::duration_cast<std::chrono::microseconds>(bfTime).count();
	std::cout << "BF Time = " << bfMicrosecondTime << " microseconds" << std::endl;
	//    genetic algorithm cost
	std::cout << "GA Cost = " << gaCost << std::endl;
	//    genetic algorithm time
	long long gaMicrosecondTime = std::chrono::duration_cast<std::chrono::microseconds>(gaTime).count();
	std::cout << "GA Time = " << gaMicrosecondTime << " microseconds" << std::endl;
	//    % optimal of genetic algorithm
	std::cout << "GA % Optimal = " << gaOptimalCost << std::endl;
	std::cout << "============================" << std::endl;


	return 0;
}
