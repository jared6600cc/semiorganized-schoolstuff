/*
 * Chris Doster && Jared Bumgardner
 * 25 Oct. 2020
 * COP4634
 * Proj. 2
 * Main.cpp
 */

 #include "collatz.hpp"
 #include <iostream>
 #include <cstring>
 #include <vector>
 #include <thread>
 #include <functional>
 #include <mutex>
 #include <ctime>

long COUNTER = 2;       	// Starts @ 2 & ends @ N
bool noLockEnabled = false;
std::mutex mtxObj;

void collatz(Histogram &h, int interval);



 /* **MAIN** */
int main(int argc, char* argv[]){
	// Definitions
	int rangeToCompute = 0;         // N
	int numberOfThreads = 0;        // T

	int actualThreads = 0;


	// Process command line arguments
	if(argc < 3){
		std::cout << "ERROR: Incorrect # of command line arguments (2 needed)" << std::endl;
		return -1;
	} else {
		rangeToCompute = atoi(argv[1]);
		numberOfThreads = atoi(argv[2]);
		if(argc > 3){
			if(strcmp(argv[3], "-nolock") == 0)
				noLockEnabled = true;
		}
	}


	// Initialize array with zeros
	Histogram hg;
	hg.createArray(rangeToCompute);
	
	// Calculate collatz sequences for numbers between 1 & N
	int collatzRangeLow = 0;
	int collatzInterval = rangeToCompute / numberOfThreads;

	struct timespec startTime, endTime;
	// start clock
	clock_gettime(CLOCK_REALTIME, &startTime);
	
	std::vector<std::thread> threadList;
	// Create M threads
	for(int i=0; i < numberOfThreads; i++)
	{
		threadList.push_back(std::thread(std::bind(collatz, hg, collatzInterval)));
		collatzRangeLow += collatzInterval;
		actualThreads++;
	}
	
	// Join M threads
	for(int i=0; i < numberOfThreads; i++)
	{
		threadList[i].join();
	}

	// End clock
	clock_gettime(CLOCK_REALTIME, &endTime);

	// calculate time difference
	double sDiff = difftime(endTime.tv_sec, startTime.tv_sec);
	long nsDiff = endTime.tv_nsec - startTime.tv_nsec; 
	if (nsDiff < 0)
	{
		nsDiff = 1000000000 - nsDiff;
		sDiff--;
	}

	std::cerr << rangeToCompute << "," << numberOfThreads << "," << sDiff << "." << nsDiff << std::endl;

	// Display results
	hg.print();

	return 0;
}


void collatz(Histogram &h, int interval)
{
	for (int i=0; i < interval; ++i)
	{
		if(!noLockEnabled)
		{
			mtxObj.lock();
		}
		// - compute the collatz stopping times for #s 2 through N
		Collatz c;
		c.createCollatzSeq(COUNTER);
		COUNTER++;
		h.incrementFrequency(c.getStoppingTime());

		if(!noLockEnabled)
		{
			mtxObj.unlock();
		}
	}

	return;
}


