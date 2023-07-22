 //Jared Bumgardner
 //COP4534: Data Structures & Algorithms 2
 //Project 3
 //22 March 2018
 
 #include <stdio.h>
 #include <sys/time.h>
 #include <time.h>
 #include <stdlib.h>
 
 
 
//============================================================
//	PLANNING												||
//============================================================
/*
 * Task: 
 *	-Write 2 solutions to Traveling Salesman Problem
 *	-Both run in one program
 *	-Terminate after n generations
 *	-Always 2 elites
 *	-1: brute force permutation program that tries all possible permutations
 *	-2: genetic algorithm inspired solution
 */
  
  
  
//============================================================
//	IMPLEMENTATION											||
//============================================================  

  //Declarations
  double cityWeights[380];		//Holds provided graph edges info
  double weightsProvided = 0;
  
  //Reads in information from cityWeights.txt & returns ptr to file
  FILE * readInWeights(){
	  //Open file
	  FILE *tmp;
	  int i = 0;
	  tmp = fopen("cityWeights.txt", "r");
	  
	  //Read file info
	  if(tmp == NULL){
		  printf("ERROR: Cannot open file.");
	  }
	  else{
		  while(fscanf(tmp, "%lf", &(cityWeights[i])) != EOF){
			  weightsProvided++;
			  i++;
		  }
	  }
	  return tmp;
  }//end readInWeights()
  
  
  void printAdjMatrix(double mtrx){}
  
  
  //Produces optimal solution to traveling salesman problem
  void bruteForceTSP(){}//end bruteForceTSP()				//TODO!
  
  
  //Produces solution to traveling salesman problem using genetic algorithm
  void genAlgTSP(){}//end genAlgTime()						//TODO!
  
  
  //MAIN
  int main(){
	  //Declarations
	  FILE *cWeights;			//edges file
	  int cWeightsIndx;			//indexes progress through read-in edges info
	  int cities;				//number of cities
	  double tours;				//number of tours
	  double generations;		//number of generations
	  double mutsPerGen;		//ratio of mutations per generation
	  double bruteForceTime;	//time taken using brute force alg. on TSP
	  double genAlgTime;		//time taken using gen alg on TSP
	  
	  //Introduction
	  printf("\n\t\t***Project 3***\n\tTraveling Salesman Problem\n\n");
	  
	  //Read city edge weights from provided resources
	  cWeights = readInWeights();
	  
	  //Get user inputs
	  printf("\n\t*USER INPUT*\n");
	  printf("*Number of cities: ");
	  scanf("%d", &cities);
	  printf("*Tours in a generation: ");
	  scanf("%lf", &tours);
	  printf("*Number of generations: ");
	  scanf("%lf", &generations);
	  printf("*%% of mutations per generation: ");
	  scanf("%lf", &mutsPerGen);
	  
	  //Setup timer
	  struct timeval * time;
	  time = (struct timeval *)malloc(sizeof(struct timeval));
	  gettimeofday(time, NULL);
	  time_t startSec;
	  
	  //Setup graph
	  double adjacencyMatrix[cities - 1][cities - 1];
	  int j = 0;	//horizontal index
	  for(int i = 0; i < cities; i++){		//vertical indexing
		  if(i >= j){
			  i++;
			  j = 0;
		  }
		  else{
			  //TODO: Setup adjacency Matrix
			  adjacencyMatrix[j][i] = cityWeights[cWeightsIndx];
			  adjacencyMatrix[i][j] = cityWeights[++cWeightsIndx];
			  cWeightsIndx++;
		  }
		  j++;
	  }
	  
	  //Run brute force algorithm
	  gettimeofday(time, NULL);
	  startSec = time->tv_sec;
			/*TODO RUN BRUTE FORCE ALG*/						//!!!
	  gettimeofday(time, NULL);
	  bruteForceTime = time->tv_sec - startSec;
	  printf("\n");
	  
	  //Run genetic algorithm
	  gettimeofday(time, NULL);
	  startSec = time->tv_sec;
			/*TODO: RUN GENETIC ALG*/							//!!!
	  gettimeofday(time, NULL);
	  genAlgTime = time->tv_sec - startSec;
	  
	  //Output results
	  printf("\n\t*OUTPUT*\n");
	  printf("Cities run: %d\n", cities);
	  printf("Optimal cost (brute force): \n");
	  printf("Time (brute force): %lf\n", bruteForceTime);
	  printf("Cost (Gen.Alg.): \n");
	  printf("Time (Gen.Alg.): %lf\n", genAlgTime);
	  printf("%% of optimal produced by Gen.Alg.: \n");
	  
	  //Close resources & end
	  fclose(cWeights);
	  return 0;
  }//end main()