/*
 * Jared Bumgardner
 * 11 Oct. 2018
 * DS&A2
 * Proj. 2
 * Main
 */
 
 
 
 #include <stdio.h>
 #include "queue.h"
 #include "simulation.h"
 
 #define QUEUESIZE = 100;
 
 
 int main(){	 
	 //Prompt for simulation parameters
	 printf("\n***************[INPUTS]***************\n");
	 printf(": (n)\n: number of arrivals\n$ ");
	 int numArrivals = 0;
	 scanf("%d", &numArrivals);
	 
	 printf("\n: (l)\n: average arrivals per time period\n$ ");
	 double avgArrivals = 0;
	 scanf("%lf", &avgArrivals);
	 
	 printf("\n: (u)\n: average custs served per time period\n$ ");
	 double avgServed = 0;
	 scanf("%lf", &avgServed);
	 
	 
	 printf("\n: (M)\n: number of service channels\n$ ");
	 int numServiceChannels = 0;
	 scanf("%d", &numServiceChannels);
	 
	 printf("************************************\n");
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 //SIMULATE
	 int serverAvailable = numServiceChannels;
	 processNextEvent();
	 
	 
	 
	 
	 
	 
	 

	 
	 //Report simulation results
	 printf("\n*****[OUTPUT]*****\n");
	 printf("Po = \n");
	 printf("L = \n");
	 printf("W = \n");
	 printf("Lq = \n");
	 printf("Wq = \n");
	 printf("******************\n");
	 
	 return 0;
 }