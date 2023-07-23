#ifndef HISTOGRAM_HPP
#define HISTOGRAM_HPP

#include <iostream>

class Histogram
{
	private:
	int *array;		// Holds computed collatz stopping times
	int sizeH;		// Holds size for ease of use
	
	public:
	// Create array initialized to 0
	void createArray(int size);

	void incrementFrequency(int i);

	void print();
};



#endif