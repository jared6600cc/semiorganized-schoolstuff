/***************************************************************
  Jared Bumgardner
  bruteForce.cpp
  Project 3

  Other comments regarding the file - description of why it is there, etc.
***************************************************************/

#include "bruteForce.hpp"

void printS(int *s, int numElements) 
{
    for (int i = 0; i < numElements; i++) 
    {
        std::cout << s[i] << ' ';
    }
    std::cout << std::endl;
}

void swap(int x, int y, int *s) 
{
    int tmp;
    tmp = s[x];
    s[x] = s[y];
    s[y] = tmp;
    return;
}

int factorial(int x) 
{
    int result = 1;
    for (int i = 1; i <= x; i++) 
    {
        result = result * i;
    }
    return result;
}

double perm1(int permsThisCall, int *s, int sSize, adjacencyMatrix citiesGraph)        // Provided by Prof. // Modified by me to evaluate instead of print each permutation
{
    int m, k, p, q, i;
    int *bestPath = new int(sSize);
    double bestPathLength = 1000000000;

    for (i = 0; i < factorial(permsThisCall)-1; i++)
    {
        m = sSize - 2;
        while (s[m] > s[m + 1])
        {
            m = m - 1;
        }
        k = sSize - 1;
        while (s[m] > s[k]) 
        {
            k = k - 1;
        }
        swap(m, k, s);
        p = m + 1;
        q = sSize - 1;
        while (p < q) 
        {
            swap(p, q, s);
            p++;
            q--;
        }
//        printS(s, sSize);
        double pathLength = 0;
        for (int i = 0; i < sSize - 1; i++) 
        {
            pathLength += citiesGraph.matrix[s[i]][s[i+1]];
        }
        if (pathLength < bestPathLength) 
        {
            bestPathLength = pathLength;
        }
    }
    return bestPathLength;
}

double bruteForceTSP(adjacencyMatrix citiesGraph, parameters params)
{
    // Prepare path
    int* s = new int[params.numCities];
    for (int i = 0; i < params.numCities; i++) 
    {
        s[i] = i;
    }

    // Test all tours
    double bestPathLength = 0;
    bestPathLength = perm1(params.numCities, s, params.numCities, citiesGraph);

    delete []s;     // delete dynamically sized array

    return bestPathLength;
}