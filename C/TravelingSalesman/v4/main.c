 /*
  * Jared Bumgardner
  * COP4534: Data Structures & Algorithms 2
  * Project 3
  * 1 Nov 2018
  */
  
  #include <stdio.h>
  #include <sys/time.h>
  #include <time.h>
  #include <stdlib.h>
  
  //Global values
  #define MAXLEN 20
  double numbers[380];

  
  //Read data in from file
  void readWithfscanf(){
	  FILE * fp = fopen("cityWeights.txt", "r");
	  int count = 0;
	  
	  while(fscanf(fp, "%lf", &numbers[count]) != EOF){
		  count++;
	  }
	  
	  fclose(fp);
  }
  
  //Solve Traveling Salesman Problem by way of Brute Force
  void bruteForceTSP(double graph[], int cities){}
  
  //Solve Traveling Salesman Problem by way of Genetic Algorithm
  void genAlgTSP(double graph[], int cities){}
  
  
  int main(){
	  //Declarations
	  int cities = 0;				//number of cities
	  int tours = 0;				//number of tours per generation
	  int generations = 0;			//number of generations
	  int mutsPerGen = 0;			//ratio of mutations per generation
	  
	  //Introduction
	  printf("\n\t\t***Project 3***\n\tTraveling Salesman Problem\n\n");
	  
	  //Read city edge weights from provided file
	  readWithfscanf();
	  
	  //Get user inputs	
	  printf("\n\t*USER INPUT*\n");
	  printf("*Number of cities: ");
	  scanf("%d", &cities);
	  double cityGraph[cities][cities];
	  printf("*Tours in a generation: ");
	  scanf("%d", &tours);
	  printf("*Number of generations: ");
	  scanf("%d", &generations);
	  printf("*%% of mutations per generation: ");
	  scanf("%d", &mutsPerGen);
	  
	  //Build Cities graph
	  int count = 0;
	  for(int i = 0; i < cities; i++){
		  for(int j = 0; j < cities; j++){
			  cityGraph[i][j] = numbers[count];
			  count++;
		  }
	  }
	  
	  //Run brute force algorithm
	  time_t startBF = time(NULL);
	  bruteForceTSP(*(cityGraph), cities);	
	  time_t endBF = time(NULL);
	  
	  //Run genetic algorithm
	  time_t startGA = time(NULL);
	  genAlgTSP(*(cityGraph), cities);	
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