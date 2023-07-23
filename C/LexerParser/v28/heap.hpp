/***************************************************************
  Jared Bumgardner
  heap.hpp
  Project 2

  This file contains the heap prototypes. (incomplete)
***************************************************************/

#ifndef HEAP_H
#define HEAP_H

#include <vector>
using std::vector;

const int pqSize = 200;

class customer
{
public:
    float arrivalTime;
    float startOfServiceTime;
    float departureTime;
    customer* nextCust;    // for linked FIFO
};

class heap
{
    customer data[pqSize];
    int tailIndex = 0;
public:
    heap(); // constructor
    void percolateUp(int root);
    customer* percolateDown(int root);
	void insert(customer c);
    customer * removeRoot();
    void print();
};

#endif // HEAP_H