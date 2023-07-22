/*   Jared Bumgardner
 *   COP4534
 *   Due: 21 March 2019
 */

#include "bruteForceTSP.h"
#include "completeGraph.h"
#include <stdio.h>

//Calculate the factorial of a given integer
int factorial(int n){
    int i;
    int result = 1;
    for(i = 2; i <= n; i++){
        result *= i;
    }
    return result;
}

//Evaluate the cost of a given tour
double evaluateCost(int *tour, int nCities, double cGraph[INPUTFILECITIES][INPUTFILECITIES]){
    //int i, j, k;#include "bruteForceTSP.h"
    //double result = 0;
    //for(i = 0; i < nCities; i++){
    //        j = tour[i];
    //        k = tour[i+1];
            //result = completeGraphPTR[j][j] + result;
    //}

    return 0;
}

//Solve the Traveling Salesman Problem by brute force
int bruteForceSolve(int nCities, double cGraph[INPUTFILECITIES][INPUTFILECITIES]){
    //Test each and all permutations for the optimal solution
    int i;
    int citiesLength = 0;
    //Set city array to generate tours
    int cityIndex[nCities];
    for(i = 0; i < nCities; i++){
        cityIndex[i] = i;
        citiesLength++;
    }

    //Get n factorial
    int nFact;
    nFact = factorial(nCities);

    //Get all permutations of the given cities
    int m, k, p, q;
    for(i =1; i < nFact; i++){
        m = citiesLength - 2;
        while(cityIndex[m] > cityIndex[m+1]){
            m = m - 1;
        }
        k = citiesLength - 1;
        while(cityIndex[m] > cityIndex[k]){
            k = k - 1;
        }

        //swap m,k
        int tmp = 0;
        tmp = cityIndex[m];
        cityIndex[m] = cityIndex[k];
        cityIndex[k] = tmp;

        p = m + 1;
        q = citiesLength - 1;
        while(p < q){
            tmp = cityIndex[p];
            cityIndex[p] = cityIndex[q];
            cityIndex[q] = tmp;

            p++;
            q--;
        }
        printf("\n");   //debug formatting

        //Is best tour?
        int currTourCost = 0;    //contains the current tour cost
        int bestTourCost = 0;   //contains the lowest tour cost

//        currTourCost = evaluateCost(cityIndex, nCities, *cGraph);         //Can't figure out how to pass nxm matrices around. RIP me.
        if(currTourCost < bestTourCost)
            bestTourCost = currTourCost;
    }

    return 0;
}
