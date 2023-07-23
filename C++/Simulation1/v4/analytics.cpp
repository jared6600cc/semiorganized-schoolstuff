/***************************************************************
  Jared Bumgardner
  analytics.cpp
  Project 2

  This file implements the analytical model (incomplete)
***************************************************************/

#include "analytics.hpp"
#include <iostream>
#include <vector>

using namespace std;

analytics::analytics()
{
    Po = -1;
    L = -1;
    W = -1;
    Lq = -1;
    Wq = -1;
}

void analytics::processStatistics()
{
}


void analytics::print()
{
    cout << endl;
    cout << "Po = " << Po << endl;
    cout << "L = " << L << endl;
    cout << "W = " << W << endl;
    cout << "Lq = " << Lq << endl;
    cout << "Wq = " << Wq << endl;
}