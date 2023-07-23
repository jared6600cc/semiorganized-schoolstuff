/***************************************************************
  Jared Bumgardner
  simulation.cpp
  Project 2

  This file contains the implementation of the simulation. (incomplete)
***************************************************************/

#include <vector>
#include <iostream>
#include <sstream>
#include <random>
#include <math.h>
#include "simulation.hpp"
#include "heap.hpp"

using namespace std;

float simulation::getNextRandomInterval(double avg) 
{
    float f = rand() / float(RAND_MAX);
    float intervalTime = float(-1 * (1.0 / avg) * log(f));
    return intervalTime;
}

void simulation::processNextEvent()
{
}

void simulation::simulate(std::vector<std::string> parameters)
{
    // Get parameters
    int lambda = stoi(parameters[1]);
    int numEvents = stoi(parameters[4]);
    int serverAvailableCnt = stoi(parameters[3]);

    // Generate first arrivals & add to PQ
    heap priorityQueue;
    for (int i = 0; i < pqSize; i++) 
    {
        customer c;
        c.arrivalTime = getNextRandomInterval(lambda);
        priorityQueue.insert(c);
        numEvents--;
    }
//    priorityQueue.print();        // Debug to determine that heap is being built corrently. Spoiler alert: It does not.

 //   while (priorityQueue.size() > 0) 
 //   {
        //processNextEvent()
        //if(moreArrivals and PQ.size <= M+1)
        //  add arrivals to PQ
        //Show simulation results (currently done elsewhere)
        // 
 //   }
}