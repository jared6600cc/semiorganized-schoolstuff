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
 
 
 
 // Models each customer that enters the simulated system
 class Customer {
	 public:
		float arrivalTime;
		float startOfServiceTime;
		float departureTime;
		
		Customer(){				// Constructor
			arrivalTime = 0;
			startOfServiceTime = 0;
			departureTime = 0;
		}
 };
 
 
 
 // Models each event that is simulated
 class Event {
	 public:
		Customer cust;
		int intervalTime;
 };

 
 
 // Overloads operator to allow for STI use of Customer class
bool operator<(const Event& e1, const Event& e2){
	return e1.intervalTime < e2.intervalTime;
}
 
 
 
 // Gets a rand# according to a negative exponential distribution
 float getNextRandomInterval(int avg){
	 // generate a random float f on the interval (0...1]
	 float randFloat = (float(rand() / float(RAND_MAX)));
	 
	 // compute interval time & return
	 float intervalTime = -1 * (1.0 / avg) * log(randFloat);
	 return intervalTime;	 
 }
 
 
 
 // Processes statistics from simulation performance									/* DEBUG NOTE: The call is never reached & idk why */
 void processStatistics(){std::cout << "ToDo: Processing Statistics!" << std::endl;}
 
 
 
 // Processes an event from the priority queue
 void processNextEvent(std::priority_queue<Event>& pq, std::queue<Customer>& cq){
	 Event currEvent = pq.top();
	 pq.pop();
	 
	 if(currEvent.cust.departureTime == 0){		// Event is ARRIVAL
		 if(serverAvailableCnt > 0){
			 serverAvailableCnt--;
			 currEvent.cust.startOfServiceTime = currEvent.cust.arrivalTime;
			 currEvent.intervalTime = getNextRandomInterval(uParam);
			 currEvent.cust.departureTime = currEvent.cust.arrivalTime + currEvent.intervalTime;
			 pq.push(currEvent);
		} else {
			// place customer in fifo....
			 cq.push(currEvent.cust);
		} 
	} else {									// Event is DEPARTURE
		serverAvailableCnt++;
		processStatistics();															/* DEBUG NOTE: Call is never reached */
		if(!cq.empty()){
			Customer currCust = cq.front();
			cq.pop();
			currCust.startOfServiceTime = currEvent.cust.arrivalTime + currEvent.intervalTime;
			currEvent.intervalTime = getNextRandomInterval(uParam);
			currCust.departureTime = currCust.startOfServiceTime + currEvent.intervalTime;
			pq.push(currEvent);
			serverAvailableCnt--;
		}
	}
 }
 
 
 
 /* **MAIN** */
int main(int argc, char* argv[]){
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

	
	// Simulate
	// - Prime queue with arrivals
	std::priority_queue <Event> pq;			// holds events according to interval time
	std::queue <Customer> cq;				// holds customers waiting for service
	serverAvailableCnt = mParam;
	int actualArrivals = 0;
	
	while(pq.size() < PQSIZE){
		Customer arrival;
		Event initialEvent;
		initialEvent.cust = arrival;
		initialEvent.intervalTime = getNextRandomInterval(lParam);
		pq.push(initialEvent);
		actualArrivals++;
	}
	
	// - event loop
	while(!pq.empty()){
		processNextEvent(pq, cq);
		if((nParam - actualArrivals > 0) && ((int)pq.size() <= serverAvailableCnt+1)){
			Customer newArrival;
			Event newEvent;
			newEvent.cust = newArrival;
			newEvent.intervalTime = getNextRandomInterval(lParam);
			pq.push(newEvent);
			actualArrivals++;
		}
	}

	
	// Report simulation results
	std::cout << "\n===== RESULTS ======" << std::endl;
	std::cout << "Po = " << std::endl;		// percent idle time
	std::cout << "L  = " << std::endl;		// average # of people in the system
	std::cout << "W  = " << std::endl;		// average time a customer spends in the system
	std::cout << "Lq = " << std::endl;		// average #s of customers in the queue
	std::cout << "Wq = " << std::endl;		// average time a customer spends waiting in queue
	std::cout << "Rho = " << std::endl;		// utilization factor for the system
	std::cout << "====================" << std::endl;
	
	std::cout << "BLESS THIS MESS" << std::endl;										/* DEBUG NOTE: Delete this silliness in the future */
	return 0;
}