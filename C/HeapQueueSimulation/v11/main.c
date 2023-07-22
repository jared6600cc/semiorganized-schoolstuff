/*
 * Jared Bumgardner
 * 11 Oct. 2018
 * DS&A2
 * Proj. 2
 * Main
 */

 #include <stdio.h>
 #include "simulation.h"
 #include "heap.h"
 
int main(){
	//Prompt for simulation parameters
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
	 printf("\n\n");
	 
	 
	 
	 
	 
	 //Simulate
	 //--place first arrivals in PQ
	 getNextRandomInterval();	//?
	 heapSize++;
	 int availableServiceChannels = numServiceChannels;
	 
	 while(heapSize > 0){	//pq is not empty
		processNextEvent();
			//if(moreArrivals and PQ.size <= M+1)
				if(heapSize <= numServiceChannels+1)
					getNextRandomInterval();
					//generate next set of arrivals
					
				heapSize--;	//TODO: remove?
		}
	 
	 
	 
	 
	 
	 //Report simulation results
	 printf("Po = \n");
	 printf("L = \n");
	 printf("W = \n");
	 printf("Lq = \n");
	 printf("Wq = \n");

	 return 0;
}