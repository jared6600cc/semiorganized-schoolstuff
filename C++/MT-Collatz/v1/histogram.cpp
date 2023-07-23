#include "histogram.hpp"

void Histogram::createArray(int size)
{
	array = new int[size];
	sizeH = size;
	for(int i=0; i < size; i++){
		array[i] = 0;
	}
}

void Histogram::incrementFrequency(int i)
{
	if (i < sizeH)
	{
		array[i]++;
	}
}

void Histogram::print()
{
	// Print the final histogram to stdout
	for(int i=0; i < sizeH; i++)
		std::cout << i << ", " << array[i] << std::endl;
}

