/*   Jared Bumgardner
 *   COP4534
 *   Due: 21 March 2019
 */

#include <stdio.h>
#include <stdlib.h>
#include "completeGraph.h"
#include "globals.h"
#include "bruteForceTSP.h"
#include "geneticTSP.h"



int main(){
    //Declarations
    FILE *inputFP = fopen("distances.txt", "r");        //input file
    char buffer[BUFFERSIZE];                            //input buffer
    double cGraph[INPUTFILECITIES][INPUTFILECITIES] = {};

    //Read data from distances.txt as doubles
    if(inputFP == NULL){
        return 1;
    } else {
        //Create complete graph for use with 20 cities
        int i = 0;  //row index
        int j = 0;  //column index
        while(fgets(buffer, BUFFERSIZE, (FILE*)inputFP) != NULL){
            //read buffer into complete graph
            cGraph[i][j] = atof(buffer);
            cGraph[j][i] = atof(buffer);
            j++;

            if(j >= INPUTFILECITIES){
                i++;
                j = i;
            }
            if(i == INPUTFILECITIES && j == INPUTFILECITIES)
                break;
        }
    }

    //Introduce program
    printf("\n\t***Project 3***");

    //Get number of cities from user
    int numCitiesInput = 0;
    printf("\n\n\tEnter # of cities that salesman must travel through: ");
    scanf("%d", &numCitiesInput);

    //Get how many individual tours are in a given generation from user
    int numToursPerGen = 0;
    printf("\tEnter # of tours per generation: ");
    scanf("%d", &numToursPerGen);

    //Get how many generations to run from user
    int numGenerations = 0;
    printf("\tEnter # of generations: ");
    scanf("%d", &numGenerations);

    //Get what percentage of a generation should be comprised of mutations form user
    int percentGenMut = 0;
    printf("\tEnter %% of mutations per generation: ");
    scanf("%d", &percentGenMut);

    //Run Brute Force Algorithm
    bruteForceSolve(numCitiesInput, cGraph);

    //Run Genetic Algorithm
//    geneticSolve();

    //Produce output
//    produceOutput();

    //Close files
    fclose(inputFP);

    return 0;
}
