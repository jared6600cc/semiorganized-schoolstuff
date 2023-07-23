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
 
 double cityWeights[380];		//holds provided graph edges info
 double * cityGraph;			//holds adjacency matrix rep. of complete graph
 double * permResults;			//holds results of tour permutations
 
 //Reads in edge weights from provided input
 double * readInWeights(int numCities){
	 //Open file
	 int i = 0;
	 FILE *tmp;
	 tmp = fopen("cityWeights.txt", "r");
	 
	 //Read file info
	 if(tmp == NULL){
		 printf("ERROR: Cannot open input file.");
		 exit(1);
	 } else {
		 while(fscanf(tmp, "%lf", &(cityWeights[i])) != EOF) {
			 i++;
		 }
	 }
	 
	 //Build adjacency matrix
	 double * amTMP = malloc(sizeof(double) * numCities);
	 double adjacencyMatrix[numCities][numCities];
	 for(int j = 0; j < numCities; j++){		//vertical indexing
		 for(int k = j; k < numCities; k++){	//horizontal indexing
			 adjacencyMatrix[k][j] = cityWeights[j];
			 adjacencyMatrix[j][k] = cityWeights[j];
		 }
	 }
	 
	 amTMP = adjacencyMatrix[0];
	 return amTMP;
 }//end readInWeights()
 
 //Swap city edges for permute() function
 void swap(double *values, int indx1, int indx2){
	 double tmp = values[indx1];
	 values[indx1] = values[indx2];
	 values[indx2] = tmp;
 }//end swap()
 
 //Recursive get all possible permutations of a list of edges
 void permute(double *values, int start, int end){
	 if(start == end){
		 return;
	 } else {
		 permute(values, start+1, end);
		 int k = 0;
		 for(k = start+1; k < end; k++){
			 if(values[start] == values[k]){
				 continue;
			 }
			 swap(values, start, k);
			 permute(values, start+1, end);
			 swap(values, start, k);
		 }
	 }
 }//end permute()
 
 //Calculate factorial of a given n
 int factorial(int n){
	 int fact = 0;
	 for(int i = 1; i <= n; ++i){
		 fact *= i;
	 }
	 return fact;
 }//end factorial()
 
 //Brute force solution to Traveling Salesman Problem
 void bruteForceTSP(double *permResults, int numCities){
	 //Evaluate permutations
	 permute(permResults, 0, numCities);
 }//end bruteForceTSP()
 
 //Genetic algorithm solution to Traveling Salesman Problem
 void genAlgTSP(){}//end genAlgTSP()
 
 //Main function
 int main(){
	 //Declarations
	 int status = 0;			//status flag for user input validation
	 int cities = 0;			//number of cities
	 int tours = 0;				//number of tours per generation
	 int generations = 0;		//number of generations
	 double mutsPerGen = 0;		//mutations per generation (<1)
	 struct timeval * time;
	 time = (struct timeval *)malloc(sizeof(struct timeval));
	 time_t startSecBF = 0;
	 time_t startMSBF = 0;
	 time_t endSecBF = 0;
	 time_t endMSBF = 0;
	 time_t startSecGA = 0;
	 time_t startMSGA = 0;
	 time_t endSecGA = 0;
	 time_t endMSGA = 0;
	 
	 //Introduction
	 printf("\n\t\t***Project 3***\n\tTraveling Salesman Problem\n\n");
	 
	 //Read in city edge weights from provided resources
	 cityGraph = readInWeights(cities);
	 
	 //Get user inputs
	 printf("\n\t*USER INPUT*\n");
	 printf("*Number of cities: ");	 
	 while(scanf("%d", &cities) != 1 || getchar() != '\n'){
		 while(getchar() != '\n');
		 printf("ERROR: Enter an integer... ");
	 }
	 
	 printf("*Tours in a generation: ");
	 while(scanf("%d", &tours) != 1 || getchar() != '\n'){
		 while(getchar() != '\n');
		 printf("ERROR: Enter an integer... ");
	 }
	 
	 printf("*Number of generations: ");
	 while(scanf("%d", &generations) != 1 || getchar() != '\n'){
		 while(getchar() != '\n');
		 printf("ERROR: Enter an integer... ");
	 }
	 
	 printf("*%% of mutations per generation: ");	 
	 while((status = scanf("%lf", &mutsPerGen)) != 1 || mutsPerGen > 1){
		 while(getchar() != '\n');
		 printf("ERROR: Enter a decimal... ");	 
	 }
	 
	 //Run brute force algorithm
	 double tmp[2][factorial(cities)];
	 permResults = tmp[0];
	 gettimeofday(time, NULL);
	 startSecBF = time->tv_sec;
	 startMSBF = time->tv_usec;
	 bruteForceTSP(permResults, cities);
	 gettimeofday(time, NULL);
	 endSecBF = time->tv_sec;
	 endMSBF = time->tv_usec;
	 
	 //Run genetic algorithm
	 gettimeofday(time, NULL);
	 startSecGA = time->tv_sec;
	 startMSGA = time->tv_usec;
	 genAlgTSP();
	 gettimeofday(time, NULL);
	 endSecGA = time->tv_sec;
	 endMSGA = time->tv_usec;
	 
	 //Output results
	 printf("\n\t*OUTPUT*\n");
	 printf("Cities run: %d\n", cities);
	 printf("Optimal cost (brute force): \n");
	 printf("Time (brute force): %ld seconds %ld microseconds\n", endSecBF - startSecBF, endMSBF - startMSBF);
	 printf("Cost (Gen.Alg.): \n");
	 printf("Time (Gen.Alg.): %ld seconds %ld microseconds\n", endSecGA - startSecGA, endMSGA - startMSGA);
	 printf("%% of optimal produced by Gen.Alg.: \n");
	 
	 //Close resources & end
	 return 0;
 }//end main()