 /*
  * Jared Bumgardner
  * COP4534: Data Structures & Algorithms 2
  * Project 3
  * 25 March 2018
  */
  
  #include <stdio.h>
  #include <sys/time.h>
  #include <time.h>
  #include <stdlib.h>
  
  void readEdgeWeights(){}
  void bruteForceTSP(){
	  int j;
	  for(int i=0; i<10000000000; i++){
		  j += i;
	  }
  }
  void genAlgTSP(){}
  
  int main(){
	  //Declarations
	  int cities = 0;				//number of cities
	  int tours = 0;				//number of tours per generation
	  int generations = 0;			//number of generations
	  int mutsPerGen = 0;			//ratio of mutations per generation
	  //double bruteForceTime = 0;	//time taken using brute force alg. on TSP
	  //double genAlgTime = 0;		//time taken using genetic alg. on TSP
	  
	  //Introduction
	  printf("\n\t\t***Project 3***\n\tTraveling Salesman Problem\n\n");
	  
	  //Read city edge weights from provided file
	  readEdgeWeights();
	  
	  //Get user inputs							//TODO: Protect against wrong inputs
	  printf("\n\t*USER INPUT*\n");
	  printf("*Number of cities: ");
	  scanf("%d", &cities);
	  printf("*Tours in a generation: ");
	  scanf("%d", &tours);
	  printf("*Number of generations: ");
	  scanf("%d", &generations);
	  printf("*%% of mutations per generation: ");
	  scanf("%d", &mutsPerGen);
	  
	  //Run brute force algorithm
	  time_t startBF = time(NULL);
	  bruteForceTSP();
	  time_t endBF = time(NULL);
	  
	  //Run genetic algorithm
	  time_t startGA = time(NULL);
	  genAlgTSP();
	  time_t endGA = time(NULL);
	  
	  //Output results
	  printf("\n\t*OUTPUT*\n");
	  printf("Cities run: %d\n", cities);
	  printf("Optimal cost (brute force): \n");
	  printf("Time (brute force): %ju\n", (uintmax_t)(endBF - startBF));
	  printf("Cost (Gen.Alg.): \n");
	  printf("Time (Gen.Alg.): %ju\n", (uintmax_t)(endGA - startGA));
	  printf("%% of optimal produced by Gen.Alg.: \n");
	  
	  //Close resources & end
	  
	  return 0;
  }//end main()