/*   Jared Bumgardner
 *   COP4534
 *   Due: 21 March 2019
 */

#ifndef BRUTEFORCETSP_H_
#define BRUTEFORCETSP_H_

#include "globals.h"

int factorial(int n);           //Calculate the factorial of a given integer
double evaluateCost(int *tour, int nCities, double cGraph[INPUTFILECITIES][INPUTFILECITIES]);   //Evaluate the cost of a given tour
int bruteForceSolve(int nCities, double cGraph[INPUTFILECITIES][INPUTFILECITIES]);              //Solve the Traveling Salesman Problem by brute force

#endif // BRUTEFORCETSP_H_
