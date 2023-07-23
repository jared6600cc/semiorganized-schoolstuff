//Main

#include <iostream>
#include "heap.hpp"
using namespace std;



int main(){
	//Declarations
	int n;
	int l;
	int m;
	int M;
	
	int Po;
	int L;
	int W;
	int Lq;
	int Wq;
	
	//User input
	cout << "n - # of arrivals to simulate\n";
	cin >> n;
	cout << "lambda L - average arrivals in a time period\n";
	cin >> l;
	cout << "mu m - average # served in a time period\n";
	cin >> m;
	cout << "M - the # of service channels\n";
	cin >> M;
	
	//Simulation
	//--place first arrivals in PQ
	//getNextRandomInterval();
	//heapSize++;
	//int availableServiceChannels = numServiceChannels;
	//while(heapSize > 0){
	//processNextEvent();
	//if(moreArrivals and PQ.size <= M+1)
	//if(heapSize <= numServiceChannels+1)
	//getNextRandomInterval();
	//generate next set of arrivals
	//heapSize--;
	//}
	
	//Analytics
	Po = 0;
	L = 0;
	W = 0;
	Lq = 0;
	Wq = 0;
	cout << "\n**ANALYTICS**\n";
	cout << "Po = " << Po << "\n";
	cout << "L = " << L << "\n";
	cout << "W = " << W << "\n";
	cout << "Lq = " << Lq << "\n";
	cout << "Wq = " << Wq << "\n";
	
	//test
	isEmpty();
	return 0;
}
