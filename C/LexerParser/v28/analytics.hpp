/***************************************************************
  Jared Bumgardner
  analytics.hpp
  Project 2

  This file contains the analytics class for the analytical model. (incomplete)
***************************************************************/

#ifndef ANALYTICS_H
#define ANALYTICS_H


class analytics
{
private:
    double Po, L, W, Lq, Wq;

public:
    analytics();       // constructor
    void processStatistics();
    void print();       // print results of simulation
};

#endif // ANALYTICS_H