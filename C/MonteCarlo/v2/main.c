/* Jared Bumgardner
 * COP4534
 * Due 4 April 2019
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>


#define INPUTSIZE 64
#define INPUTDATAPOINTS 5
#define NAMESIZEMAX 32



void readInputFile(FILE *inputPTR, int data[5]){
    //Declarations
    int i = 0;
    char buffer[INPUTSIZE];

    //Try and open input file
    if(!inputPTR){      //File does not exist
        perror("Input file missing");
    } else {            //File exists
        while(fgets(buffer, INPUTSIZE, (FILE*)inputPTR)){
            data[i] = atoi(buffer);
            i++;
        }//end while
    }//end else
}//end readInputFile()



void printSimParams(int data[INPUTDATAPOINTS]){
    printf("\tNumber of batches of items: %d\n", data[0]);
    printf("\tNumber of items in each batch: %d\n", data[1]);
    printf("\tPercentage of batches containing bad items: %d%%\n", data[2]);
    printf("\tPercentage of items that are bad in a bad set: %d%%\n", data[3]);
    printf("\tItems sampled from each set: %d\n", data[4]);
}//end printSimParams()



int generateDataSets(int data[INPUTDATAPOINTS]){
    //Declarations
    int i, j, totBad;
    int badSets = 0;
    FILE* dataSets[data[0]];        //Holds references to all current datasets
    char fileName[NAMESIZEMAX];     //Holds filename for current data set

    printf("\nGenerating data sets:\n");
    //Create files
    for(i = 0; i < data[0]; i++){
        //Create current data set
        totBad = 0;     //Reset count of bad chips in current set
        sprintf(fileName, "ds%d.txt", i);
        dataSets[i] = fopen(fileName,"w+");

        //Decide if data set is bad
        int randSeed = rand() % 100;
        if(randSeed < data[2]){     //Check against % of bad sets
            //BAD SET
            badSets++;
            //Populate bad set
            for(j = 0; j < data[1]; j++){
                randSeed = rand() % 100;
                if(randSeed < data[3]){
                    //Place bad chip
                    fputs("b\n", dataSets[i]);
                    totBad++;
                } else {
                    //Place good chip
                    fputs("g\n", dataSets[i]);
                }//end else
            }//end for
            printf("\tCreate bad set batch %d, totBad = %d, total = %d, badpct = %d\n", i, totBad, data[1], data[3]);
        } else {
            //GOOD SET
            for(j = 0; j < data[1]; j++){
                fputs("g\n", dataSets[i]);
            }//end for
        }//end else
    fclose(dataSets[i]);
    }//end for
    printf("\tTotal bad sets = %d\n\n", badSets);
    return badSets;
}//end generateDataSets



void analyzeDataSets(int data[INPUTDATAPOINTS], int numBad){
    //Declarations
    int i, j;                       //index
    int totalBad = 0;
    int marked = 0;                 //Flag for reporting a bad batch
    float result = 0;               //Contains for a result of simulation
    char buffer[INPUTSIZE];         //Holds chip info from data set
    char fileName[NAMESIZEMAX];     //Holds filename for current data set
    FILE* dataSets[data[0]];        //Holds references to all current datasets

    printf("\nAnalyzing data sets:\n");
    for(i = 0; i < data[0]; i++){           //Check all batches for bad chips
        sprintf(fileName, "ds%d.txt", i);
        dataSets[i] = fopen(fileName,"r");
        marked = 0;

        if((dataSets[i] = fopen(fileName, "r")) == NULL){   //File does not open
            perror("error opening file");
        } else {
            for(j = 0; j < data[4]; j++){
                if(fgets(buffer, INPUTSIZE, dataSets[i])){
                    if(buffer[0] == 'b'){
                        printf("\tbatch %d is bad\n", i);
                        totalBad++;
                        marked = 1;
                    }//end if
                }//end if
            if(marked == 1)
                break;
            }//end while
        }//end else

        //Cleanup
        fclose(dataSets[i]);
    }//end for

    //Report simulation results
    double base = (100 - data[3])*(.01);
    printf("\nBase = %lf\texponent = %d", base, data[4]);
    printf("\nP(failure to detect bad batch) = %lf", pow(base, data[4]));
    result = (100 - (double)numBad / (double)totalBad);
    printf("\nPercentage of bad batches detected = %.1lf%%\n", result);

    //Cleanup
    for(i = 0; i < data[0]; i++){
        fclose(dataSets[i]);
        sprintf(fileName, "ds%d.txt", i);
        remove(fileName);
    }//end for
}//end analyzeDataSets()



int main()
{
    //Declarations
    int numBad = 0;     //Contains number of bad sets per simulation
    srand(time(0));     //Initialize random number generator

    //Read data from input files
    FILE *t1PTR, *t2PTR, *t3PTR, *t4PTR;
    int t1Data[5], t2Data[5], t3Data[5], t4Data[5];     //Holds data from input files

    t1PTR = fopen("t1.txt", "r");   //Read t1.txt
    readInputFile(t1PTR, t1Data);
    fclose(t1PTR);

    t2PTR = fopen("t2.txt", "r");   //Read t2.txt
    readInputFile(t2PTR, t2Data);
    fclose(t2PTR);

    t3PTR = fopen("t3.txt", "r");   //Read t3.txt
    readInputFile(t3PTR, t3Data);
    fclose(t3PTR);

    t4PTR = fopen("t4.txt", "r");   //Read t4.txt
    readInputFile(t4PTR, t4Data);
    fclose(t4PTR);

    //SIMULATION 1
        printf("SIMULATION 1\n");
        //Print simulation parameters
        printSimParams(t1Data);
        //Generate
        numBad = generateDataSets(t1Data);
        //Analyze
        analyzeDataSets(t1Data, numBad);
    //SIMULATION 2
        printf("\n\nSIMULATION 2\n");
        //Print simulation parameters
        printSimParams(t2Data);
        //Generate
        numBad = generateDataSets(t2Data);
        //Analyze
        analyzeDataSets(t2Data, numBad);
    //SIMULATION 3
        printf("\n\nSIMULATION 3\n");
        //Print simulation parameters
        printSimParams(t3Data);
        //Generate
        numBad = generateDataSets(t3Data);
        //Analyze
        analyzeDataSets(t3Data, numBad);
    //SIMULATION 4
        printf("\n\nSIMULATION 4\n");
        //Print simulation parameters
        printSimParams(t4Data);
        //Generate
        numBad = generateDataSets(t4Data);
        //Analyze
        analyzeDataSets(t4Data, numBad);

    return 0;
}
