/***************************************************************
  Jared Bumgardner
  simulation.hpp
  Project 2

  This file contains necessary functions to run the simulation. (incomplete)
***************************************************************/

#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include <string>

class simulation
{
public:
    void simulate(std::vector<std::string> parameters);       // constructor
    float getNextRandomInterval(double avg);
    void processNextEvent();

};


#endif // SIMULATION_H