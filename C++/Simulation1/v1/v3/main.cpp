/*
 * Jared Bumgardner
 * 15 Nov. 2020
 * DS&A2
 * Proj. 4
 * Main.cpp : Monte Carlo
 */


 #include <vector>
 #include <iostream>
 #include <fstream>
 #include <ctime>
 #include <stdlib.h>


 /* **MAIN** */
int main(int argc, char* argv[]){
	// Declarations
	std::vector<std::string> inputParameters;
	std::string line;
		
		
	// Simulation 1
	std::cout << std::endl << std::endl;
	std::cout << "		SIMULATION 1" << std::endl;
	// Get simulation parameters
	std::ifstream t1InputFile("t1.txt");
	if(t1InputFile){
		while(std::getline(t1InputFile, line)){
			if(line.size() > 0){
				inputParameters.push_back(line);
			}
		}
	} else { std::cout << "T1 NOT Found!" << std::endl;}
	t1InputFile.close();
	std::cout << std::endl;
		
	// Print simulation parameters
	double numBatches = std::stod(inputParameters.at(0));
	std::cout << "Number of batches of items					" << numBatches << std::endl;
	double numItems = std::stod(inputParameters.at(1));
	std::cout << "Number of items in each batch					" << numItems << std::endl;
	double percBadBatches = std::stod(inputParameters.at(2));
	std::cout << "Percentage of batches containing bad items			" << percBadBatches << std::endl;
	double percBadItems = std::stod(inputParameters.at(3));
	std::cout << "Percentage of items that are bad in a bad batch			" << percBadItems << std::endl;
	double numSampledPerBatch = std::stod(inputParameters.at(4));
	std::cout << "Items sampled from each batch 					" <<	numSampledPerBatch	<< std::endl;
	std::cout << std::endl;
		
	// Generate data sets
	int totalBadBatches = 0;
	srand((unsigned) time(0));
	for(int i = 0; i < numBatches; i++){
		std::ofstream outFile;
		outFile.open("ds" + std::to_string(i) + ".txt");
			
		int itemType, actualBadChips = 0;
		int batchType = rand() % (int)numBatches;
		if(batchType < percBadBatches){
			// Bad batch!
			totalBadBatches++;
			for(int j = 0; j < numItems; j++){
				itemType = rand() % (int)numItems;
				if(itemType < percBadItems){
					outFile << "b " << std::endl;
					actualBadChips++;
				} else {
					outFile << "g " << std::endl;
				}
			}
			std::cout << "Create bad set batch # " << i << ", totBad = " << actualBadChips << ", total = " << numItems << ", badpct = " << percBadItems << std::endl;
		} else {
			// Good batch!
			for(int j = 0; j < numItems; j++){
				outFile << "g " << std::endl;
			}
		}
		outFile.close();
	}
	std::cout << "Total bad sets = " << totalBadBatches << std::endl;
	std::cout << std::endl;


	
	// Monte Carlo Algorithm
	std::cout << "Analyzing Data Sets:" << std::endl;
	int r, badBatchesFound = 0;
	std::string s, u;
	std::ifstream dataset;
	for(int i = 0; i < numBatches; i++){
		s = "ds" + std::to_string(i) + ".txt";
		dataset.open(s);
		for(int j = 0; j < numSampledPerBatch; j++){
			r = rand() % (int)numItems;
			if(dataset.is_open()){
				dataset.seekg(std::ios::beg);
				for(int k = 1; k <= r; k++){
					std::getline(dataset, u);
				}
				if(u.compare("b ") == 0){
					std::cout << "batch #" << i << " is bad" << std::endl;
					badBatchesFound++;
					continue;
				}
			} else { std::cout << "ERROR DATASET NOT Found!" << std::endl; break;}
		} 
		dataset.close();
	}
	std::cout << std::endl;


	
	// Report simulation results
	std::cout << "Base = " << (100 - percBadItems)/100 << std::endl;
	std::cout << "Exponent = " << numSampledPerBatch << std::endl;
	std::cout << "P(failure to detect bad batch) = " << (1 - ((double)totalBadBatches/100)) << std::endl;
	std::cout << "Percentage of bad batches actually detected = " << ((double)badBatchesFound/(double)totalBadBatches) << std::endl;
	
	
	// Simulation 2
	std::cout << std::endl << std::endl;
	std::cout << "		Simulation 2" << std::endl;
	// Get simulation parameters
	std::ifstream t2InputFile("t2.txt");
	if(t2InputFile){
		while(std::getline(t2InputFile, line)){
			if(line.size() > 0){
				inputParameters.push_back(line);
			}
		}
	} else { std::cout << "T2 NOT Found!" << std::endl;}
	t2InputFile.close();
	std::cout << std::endl;
		
	// Print simulation parameters
	numBatches = std::stod(inputParameters.at(0));
	std::cout << "Number of batches of items					" << numBatches << std::endl;
	numItems = std::stod(inputParameters.at(1));
	std::cout << "Number of items in each batch					" << numItems << std::endl;
	percBadBatches = std::stod(inputParameters.at(2));
	std::cout << "Percentage of batches containing bad items			" << percBadBatches << std::endl;
	percBadItems = std::stod(inputParameters.at(3));
	std::cout << "Percentage of items that are bad in a bad batch			" << percBadItems << std::endl;
	numSampledPerBatch = std::stod(inputParameters.at(4));
	std::cout << "Items sampled from each batch 					" <<	numSampledPerBatch	<< std::endl;
	std::cout << std::endl;
	
	// Generate data sets
	totalBadBatches = 0;
	for(int i = 0; i < numBatches; i++){
		std::ofstream outFile;
		outFile.open("ds" + std::to_string(i) + ".txt");
			
		int itemType, actualBadChips = 0;
		int batchType = rand() % (int)numBatches;
		if(batchType < percBadBatches){
			// Bad batch!
			totalBadBatches++;
			for(int j = 0; j < numItems; j++){
				itemType = rand() % (int)numItems;
				if(itemType < percBadItems){
					outFile << "b " << std::endl;
					actualBadChips++;
				} else {
					outFile << "g " << std::endl;
				}
			}
			std::cout << "Create bad set batch # " << i << ", totBad = " << actualBadChips << ", total = " << numItems << ", badpct = " << percBadItems << std::endl;
		} else {
			// Good batch!
			for(int j = 0; j < numItems; j++){
				outFile << "g " << std::endl;
			}
		}
		outFile.close();
	}
	std::cout << "Total bad sets = " << totalBadBatches << std::endl;
	std::cout << std::endl;


	
	// Monte Carlo Algorithm
	std::cout << "Analyzing Data Sets:" << std::endl;
	r = 0;
	badBatchesFound = 0;
	for(int i = 0; i < numBatches; i++){
		s = "ds" + std::to_string(i) + ".txt";
		dataset.open(s);
		for(int j = 0; j < numSampledPerBatch; j++){
			r = rand() % (int)numItems;
			if(dataset.is_open()){
				dataset.seekg(std::ios::beg);
				for(int k = 1; k <= r; k++){
					std::getline(dataset, u);
				}
				if(u.compare("b ") == 0){
					std::cout << "batch #" << i << " is bad" << std::endl;
					badBatchesFound++;
					continue;
				}
			} else { std::cout << "ERROR DATASET NOT Found!" << std::endl; break;}
		} 
		dataset.close();
	}
	std::cout << std::endl;


	
	// Report simulation results
	std::cout << "Base = " << (100 - percBadItems)/100 << std::endl;
	std::cout << "Exponent = " << numSampledPerBatch << std::endl;
	std::cout << "P(failure to detect bad batch) = " << (1 - ((double)totalBadBatches/100)) << std::endl;
	std::cout << "Percentage of bad batches actually detected = " << ((double)badBatchesFound/(double)totalBadBatches) << std::endl;
	
	
	
		// Simulation 3
	std::cout << std::endl << std::endl;	
	std::cout << "		Simulation 3" << std::endl;
	// Get simulation parameters
	std::ifstream t3InputFile("t3.txt");
	if(t3InputFile){
		while(std::getline(t3InputFile, line)){
			if(line.size() > 0){
				inputParameters.push_back(line);
			}
		}
	} else { std::cout << "T3 NOT Found!" << std::endl;}
	t3InputFile.close();
	std::cout << std::endl;
		
	// Print simulation parameters
	numBatches = std::stod(inputParameters.at(0));
	std::cout << "Number of batches of items					" << numBatches << std::endl;
	numItems = std::stod(inputParameters.at(1));
	std::cout << "Number of items in each batch					" << numItems << std::endl;
	percBadBatches = std::stod(inputParameters.at(2));
	std::cout << "Percentage of batches containing bad items			" << percBadBatches << std::endl;
	percBadItems = std::stod(inputParameters.at(3));
	std::cout << "Percentage of items that are bad in a bad batch			" << percBadItems << std::endl;
	numSampledPerBatch = std::stod(inputParameters.at(4));
	std::cout << "Items sampled from each batch 					" <<	numSampledPerBatch	<< std::endl;
	std::cout << std::endl;
	
	// Generate data sets
	totalBadBatches = 0;
	for(int i = 0; i < numBatches; i++){
		std::ofstream outFile;
		outFile.open("ds" + std::to_string(i) + ".txt");
			
		int itemType, actualBadChips = 0;
		int batchType = rand() % (int)numBatches;
		if(batchType < percBadBatches){
			// Bad batch!
			totalBadBatches++;
			for(int j = 0; j < numItems; j++){
				itemType = rand() % (int)numItems;
				if(itemType < percBadItems){
					outFile << "b " << std::endl;
					actualBadChips++;
				} else {
					outFile << "g " << std::endl;
				}
			}
			std::cout << "Create bad set batch # " << i << ", totBad = " << actualBadChips << ", total = " << numItems << ", badpct = " << percBadItems << std::endl;
		} else {
			// Good batch!
			for(int j = 0; j < numItems; j++){
				outFile << "g " << std::endl;
			}
		}
		outFile.close();
	}
	std::cout << "Total bad sets = " << totalBadBatches << std::endl;
	std::cout << std::endl;


	
	// Monte Carlo Algorithm
	std::cout << "Analyzing Data Sets:" << std::endl;
	r = 0;
	badBatchesFound = 0;
	for(int i = 0; i < numBatches; i++){
		s = "ds" + std::to_string(i) + ".txt";
		dataset.open(s);
		for(int j = 0; j < numSampledPerBatch; j++){
			r = rand() % (int)numItems;
			if(dataset.is_open()){
				dataset.seekg(std::ios::beg);
				for(int k = 1; k <= r; k++){
					std::getline(dataset, u);
				}
				if(u.compare("b ") == 0){
					std::cout << "batch #" << i << " is bad" << std::endl;
					badBatchesFound++;
					continue;
				}
			} else { std::cout << "ERROR DATASET NOT Found!" << std::endl; break;}
		} 
		dataset.close();
	}
	std::cout << std::endl;


	
	// Report simulation results
	std::cout << "Base = " << (100 - percBadItems)/100 << std::endl;
	std::cout << "Exponent = " << numSampledPerBatch << std::endl;
	std::cout << "P(failure to detect bad batch) = " << (1 - ((double)totalBadBatches/100)) << std::endl;
	std::cout << "Percentage of bad batches actually detected = " << ((double)badBatchesFound/(double)totalBadBatches) << std::endl;
	
	
	
		// Simulation 4
	std::cout << std::endl << std::endl;		
	std::cout << "		Simulation 4" << std::endl;
	// Get simulation parameters
	std::ifstream t4InputFile("t4.txt");
	if(t4InputFile){
		while(std::getline(t4InputFile, line)){
			if(line.size() > 0){
				inputParameters.push_back(line);
			}
		}
	} else { std::cout << "T4 NOT Found!" << std::endl;}
	t4InputFile.close();
	std::cout << std::endl;
		
	// Print simulation parameters
	numBatches = std::stod(inputParameters.at(0));
	std::cout << "Number of batches of items					" << numBatches << std::endl;
	numItems = std::stod(inputParameters.at(1));
	std::cout << "Number of items in each batch					" << numItems << std::endl;
	percBadBatches = std::stod(inputParameters.at(2));
	std::cout << "Percentage of batches containing bad items			" << percBadBatches << std::endl;
	percBadItems = std::stod(inputParameters.at(3));
	std::cout << "Percentage of items that are bad in a bad batch			" << percBadItems << std::endl;
	numSampledPerBatch = std::stod(inputParameters.at(4));
	std::cout << "Items sampled from each batch 					" <<	numSampledPerBatch	<< std::endl;
	std::cout << std::endl;
	
	// Generate data sets
	totalBadBatches = 0;
	for(int i = 0; i < numBatches; i++){
		std::ofstream outFile;
		outFile.open("ds" + std::to_string(i) + ".txt");
			
		int itemType, actualBadChips = 0;
		int batchType = rand() % (int)numBatches;
		if(batchType < percBadBatches){
			// Bad batch!
			totalBadBatches++;
			for(int j = 0; j < numItems; j++){
				itemType = rand() % (int)numItems;
				if(itemType < percBadItems){
					outFile << "b " << std::endl;
					actualBadChips++;
				} else {
					outFile << "g " << std::endl;
				}
			}
			std::cout << "Create bad set batch # " << i << ", totBad = " << actualBadChips << ", total = " << numItems << ", badpct = " << percBadItems << std::endl;
		} else {
			// Good batch!
			for(int j = 0; j < numItems; j++){
				outFile << "g " << std::endl;
			}
		}
		outFile.close();
	}
	std::cout << "Total bad sets = " << totalBadBatches << std::endl;
	std::cout << std::endl;


	
	// Monte Carlo Algorithm
	std::cout << "Analyzing Data Sets:" << std::endl;
	r = 0;
	badBatchesFound = 0;
	for(int i = 0; i < numBatches; i++){
		s = "ds" + std::to_string(i) + ".txt";
		dataset.open(s);
		for(int j = 0; j < numSampledPerBatch; j++){
			r = rand() % (int)numItems;
			if(dataset.is_open()){
				dataset.seekg(std::ios::beg);
				for(int k = 1; k <= r; k++){
					std::getline(dataset, u);
				}
				if(u.compare("b ") == 0){
					std::cout << "batch #" << i << " is bad" << std::endl;
					badBatchesFound++;
					continue;
				}
			} else { std::cout << "ERROR DATASET NOT Found!" << std::endl; break;}
		} 
		dataset.close();
	}
	std::cout << std::endl;


	
	// Report simulation results
	std::cout << "Base = " << (100 - percBadItems)/100 << std::endl;
	std::cout << "Exponent = " << numSampledPerBatch << std::endl;
	std::cout << "P(failure to detect bad batch) = " << (1 - ((double)totalBadBatches/100)) << std::endl;
	std::cout << "Percentage of bad batches actually detected = " << ((double)badBatchesFound/(double)totalBadBatches) << std::endl;
	
	return 0;
}
