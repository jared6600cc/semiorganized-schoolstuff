/*
 * Chris Doster && Jared Bumgardner
 * 25 Oct. 2020
 * COP4634
 * Proj. 2
 * Main.cpp
 */



 #include <iostream>
 #include <cstring>
 #include <vector>
 #include <pthread.h>
 #include <mutex>

 int COUNTER = 2;       // Starts @ 2 & ends @ N
 bool noLockEnabled = false;
 pthread_mutex_t mtxObj;    // TODO : Move?



 void *tfunc(void * threadID){
     if(!noLockEnabled)
            pthread_mutex_lock(&mtxObj);
     int tid;
     tid = *((int*)&threadID);
     std::cout << "Thread ID, " << tid << std::endl;
     if(!noLockEnabled)
            pthread_mutex_unlock(&mtxObj);
     pthread_exit(NULL);
}



 /* **MAIN** */
int main(int argc, char* argv[]){
	// Definitions
	int rangeToCompute = 0;         // N
	int numberOfThreads = 0;        // M

	int actualThreads = 0;      // DEBUG : Ensuring that all threads are *Actually* created

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


	// - initialize array with zeros (see 'MT Collatz.pdf')
	// - create threads
	pthread_t threadList[numberOfThreads];
	pthread_mutex_init(&mtxObj, NULL);
	int rVal;

	for(int i=0; i < numberOfThreads; i++){                                      // Create M threads
        rVal = pthread_create(&threadList[i], NULL, tfunc, (void *)i);
        if(rVal){
            std::cout << "Error: unable to create thread, " << rVal << std::endl;
            exit(-1);
        } else {actualThreads++;}
	}

	std::cout << "Actual Threads Created: " << actualThreads << std::endl;      // DEBUG



	// - compute the collatz stopping times for #s 2 through N
	// - print the final histogram to stdout in the following format
	// --- <k=1,....,N>, <frequency of Collatz stopping times where i = k>

	return 0;
}
