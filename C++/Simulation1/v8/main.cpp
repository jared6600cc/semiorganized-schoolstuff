/*
 * Jared Bumgardner
 * 18 Oct. 2020
 * DS&A2
 * Proj. 2
 * Main.cpp : Main simulation loop
 */



 #include <iostream>
 #include <cstdlib>
 #include <math.h>
 #include <bits/stdc++.h>

 #define PQSIZE 200
 int nParam, lParam, uParam, mParam;				// User Parameters
 int serverAvailableCnt;							// Simulation variable
 int customerWaitedCnt;								// Statistics variable
 float currentWaitTime;                               // Statistics variable
 float totalWaitTime;                                 // Statistics variable
 float serviceTime;                                   // Statistics variable
 float idleTime;                                      // Statistics variable
 float simTime;


 // Models each customer that enters the simulated system
 class Customer {
	 public:
		float arrivalTime;
		float startOfServiceTime;
		float departureTime;

		Customer(){				// Constructor
			arrivalTime = -1;
			startOfServiceTime = -1;
			departureTime = -1;
		}
 };



 // Models each event that is simulated
 class Event {
	 public:
		Customer cust;
		float intervalTime;

		Event(){
		    intervalTime = 0;
		}
 };



 // Overloads operator to allow for STI use of Customer class
bool operator<(const Event& e1, const Event& e2){
	return e1.intervalTime > e2.intervalTime;
}



 // Gets a rand# according to a negative exponential distribution
 float getNextRandomInterval(int avg){
	 // generate a random float f on the interval (0...1]
	 float randFloat = (float(rand() / float(RAND_MAX)));

	 // compute interval time & return
	 float intervalTime = -1 * (1.0 / avg) * log(randFloat);
	 return intervalTime;
 }



 // Processes statistics from simulation performance
 void processStatistics(Customer processMe){
     currentWaitTime = processMe.startOfServiceTime - processMe.arrivalTime;

     if(currentWaitTime > 0)
        customerWaitedCnt++;
std::cout << "STATS: customerWaitedCnt: " << customerWaitedCnt << std::endl;       // DEBUG
     totalWaitTime = totalWaitTime + currentWaitTime;
std::cout << "STATS: totalWaitTime: " << totalWaitTime << std::endl;               // DEBUG
     serviceTime = serviceTime + (processMe.departureTime - processMe.startOfServiceTime);
std::cout << "STATS: serviceTime: " << serviceTime << std::endl;               // DEBUG

std::cout << "STATS: serverAvailableCnt: " << serverAvailableCnt << std::endl;               // DEBUG
     if(serverAvailableCnt == mParam)
        idleTime++;                                          // Probably not what you meant
std::cout << "STATS: indleTime: " << idleTime << std::endl;               // DEBUG
    simTime = processMe.departureTime;
std::cout << "SIMTIME: " << simTime << std::endl;      //DEBUG
std::cout << "RHO: " << serviceTime/(mParam * simTime) << std::endl;      //DEBUG

 }



 // Processes an event from the priority queue
 void processNextEvent(std::priority_queue<Event>& pq, std::queue<Customer>& cq){
     Event currEvent = pq.top();
     pq.pop();
std::cout << "pq total: " << pq.size() << std::endl;
     if(currEvent.cust.departureTime == -1){      // Arrival Event
        std::cout << "Arrival event" << std::endl;
        if(serverAvailableCnt > 0){
            serverAvailableCnt--;
            std::cout << "servers available:" << serverAvailableCnt << std::endl;
            currEvent.cust.startOfServiceTime = currEvent.cust.arrivalTime;
            currEvent.cust.departureTime = currEvent.cust.arrivalTime + getNextRandomInterval(uParam);
            currEvent.intervalTime = currEvent.cust.departureTime;
//            simTime = currEvent.cust.departureTime;
            pq.push(currEvent);
        } else {
            // place customer in fifo queue
            cq.push(currEvent.cust);

        }
     } else {                                   // Departure Event
         std::cout << "Departure event" << std::endl;
         serverAvailableCnt++;
         processStatistics(currEvent.cust);
         if(!cq.empty()){
			Customer currCust = cq.front();
			cq.pop();
			currCust.startOfServiceTime = currEvent.cust.arrivalTime + currEvent.intervalTime;
			currCust.departureTime = currCust.startOfServiceTime + getNextRandomInterval(uParam);
			currEvent.cust = currCust;
			currEvent.intervalTime = currCust.departureTime;
			pq.push(currEvent);
			serverAvailableCnt--;
        }
    }
}

int factorial(int x){return (x==0) || (x==1) ? 1 : x* factorial(x-1);}

 /* **MAIN** */
int main(){
    srand((unsigned int)time(NULL));				// Seed timer for RNG

    // Get simulation parameters from user
	std::string userInput = "";
	std::cout << "========= QUEUE SIMULATOR 2020 =========" << std::endl;
	std::cout << "Enter number of arrivals (n): " << std::endl;				// n
	std::getline(std::cin, userInput);
	nParam = stoi(userInput);
	std::cout << "Enter average arrivals (l): " << std::endl;				// lambda
	std::getline(std::cin, userInput);
	lParam = stoi(userInput);
	std::cout << "Enter average customers served (u): " << std::endl;		// mu
	std::getline(std::cin, userInput);
	uParam = stoi(userInput);
	std::cout << "Enter number of service channels (M): " << std::endl;		// M
	std::getline(std::cin, userInput);
	mParam = stoi(userInput);
	std::cout << "========================================" << std::endl;

	// - Prime queue with arrivals
	std::priority_queue <Event> pq;			// holds events according to interval time
	std::queue <Customer> cq;				// holds customers waiting for service
	serverAvailableCnt = mParam;
	int actualArrivals = 0;

	while(pq.size() < PQSIZE){
		Customer arrival;
		arrival.arrivalTime = simTime + getNextRandomInterval(lParam);
		Event initialEvent;
		initialEvent.cust = arrival;
		initialEvent.intervalTime = arrival.arrivalTime;
		pq.push(initialEvent);
		actualArrivals++;
	}

    // - event loop
	while(!pq.empty()){
	    processNextEvent(pq, cq);
        if((nParam - actualArrivals > 0) && ((int)pq.size() <= serverAvailableCnt+1)){
			Customer newArrival;
			newArrival.arrivalTime = simTime + getNextRandomInterval(lParam);
			Event newEvent;
			newEvent.cust = newArrival;
			newEvent.intervalTime = newArrival.arrivalTime;
			pq.push(newEvent);
			actualArrivals++;
		}
	}

	// Display simulation results
	std::cout << std::endl << "SIMULATION RESULTS" << std::endl;
	int tmp = 0;
	for(int i=0; i < mParam-1; i++){
        tmp = ((1/factorial(i))*pow((lParam/uParam), i));
        }
    int p0Result = 1 / (tmp + (1/factorial(mParam))*pow((lParam/uParam), mParam)*((mParam*uParam)/(mParam*(uParam-lParam))));
    std::cout << "RESULTS: P0 = " << p0Result << std::endl;
    int lResult = (((lParam*uParam)*(pow(lParam/uParam, mParam))) / (factorial(mParam-1)*(pow((mParam*uParam - lParam), 2)))*(p0Result)) + (lParam/uParam);
    std::cout << "RESULTS: L = " << lResult << std::endl;
    int wResult = (lResult/lParam);
    std::cout << "RESULTS: W = " << wResult << std::endl;
    int lqResult = lResult - (lParam/uParam);
    std::cout << "RESULTS: Lq = " << lqResult << std::endl;
    int wqResult = lqResult/lParam;
    std::cout << "RESULTS: Wq = " << wqResult << std::endl;
    int rhoResult = (lParam / (mParam*uParam));
    std::cout << "RESULTS: RHO = " << rhoResult << std::endl;
	return 0;
}
