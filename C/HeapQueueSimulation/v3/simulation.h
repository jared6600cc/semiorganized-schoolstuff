#ifndef simulation
#define simulation

struct Customer{
	float arrivalTime;
	float startOfServiceTime;
	float departureTime;
	struct Customer * next;
};

struct Event{
	int type;
	struct Customer * cust;
};


int processNextEvent();

  
#endif
