/***************************************************************
  Jared Bumgardner
  heap.cpp
  Project 2

  This file implements a min heap (priority queue adt). (incomplete: can't get heap to build corrently idk where the issue exists)
***************************************************************/

#include <iostream>
#include <math.h>
#include "heap.hpp"

using namespace std;

heap::heap()
{
}

void heap::percolateUp(int root) 
{
    // Declarations
    int minVal = 0;

    // Check parent
    while (data[root / 2].arrivalTime > data[root].arrivalTime) 
    {
        swap(data[root / 2], data[root]);
        percolateUp(data[root / 2].arrivalTime);
    }
}

customer* heap::percolateDown(int root) 
{
    customer* tmp = &data[0];
    data[0] = data[tailIndex];
    tailIndex--;

    // Check children nodes for priority
    if (data[2 * root + 1].arrivalTime < data[root].arrivalTime) 
    {
        swap(data[2*root+1], data[root]);
        percolateDown(root);
    }


    return tmp;
}

void heap::insert(customer c) 
{
    if (tailIndex >= 200)    // Check if heap is full
    {
        cout << "Error: Insertion failed (Heap is full)" << endl;
    }
    else 
    {
        data[tailIndex] = c;
        percolateUp(tailIndex);
        tailIndex++;
    }
}

customer * heap::removeRoot() 

{
    return percolateDown(0);
}

void heap::print() 
{
    customer* tmp;
    for (int i = 0; i < pqSize; i++) 
    {
        tmp = removeRoot();
        cout << "heap[" << i << "]: " << data[i].arrivalTime << endl;
    }
}