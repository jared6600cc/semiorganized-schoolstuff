#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void readInputFile(FILE *inputPTR, int data[5]){
    int i = 0;
    char buffer[32];        //Magic number
    if(!inputPTR){
        perror("Input file missing");
    } else {
        while(fgets(buffer, 32, (FILE*)inputPTR)){
            data[i] = atoi(buffer);
            i++;
        }
    }
}

void printSimParams(int data[5]){
    printf("\tNumber of batches of items: %d\n", data[0]);
    printf("\tNumber of items in each batch: %d\n", data[1]);
    printf("\tPercentage of batches containing bad items: %d%%\n", data[2]);
    printf("\tPercentage of items that are bad in a bad set: %d%%\n", data[3]);
    printf("\tItems sampled from each set: %d\n", data[4]);
}

void generateDataSets(int data[5], FILE *inputFile, char fileName[12]){
    FILE* dataSets1[data[0]];
    int i, j, totBad, badSets = 0;


    printf("\nGenerating data sets:\n");
    for(i = 0; i < data[0]; i++){
        totBad = 0;
        sprintf(fileName, "ds%d.txt", i);
        dataSets1[i] = fopen(fileName,"w+");

        //decide if batch is bad
        int randSeed = rand() % 100;
        if(randSeed < data[2]){
            //BAD SET
            badSets++;
            for(j = 0; j < data[1]; j++){
                randSeed = rand() % 100;
                if(randSeed < data[3]){   //Bad chip
                    fputs("b\n", dataSets1[i]);
                    totBad++;
                } else {    //Good chip
                    fputs("g\n", dataSets1[i]);
                }
            }
            printf("Create bad set batch %d, totBad = %d, total = %d, badpct = %d\n", i, totBad, data[1], data[3]);
        } else {
            //GOOD SET
            for(j = 0; j < data[1]; j++){
                fputs("g\n", dataSets1[i]);
            }
        }
    }
    printf("Total bad sets = %d\n\n", badSets);

    //Cleanup
    fclose(inputFile);
}

void analyzeDataSets(int data[5]){
    int i = 0;
    int isBad = 0;
    printf("Analyzing Data Sets:\n");

    for(i = 0; i < data[4]; i++){

    }

    printf("Base = \nexponent = \n");
    printf("P(failure to detect bad batch) = \n");
    printf("Percentage of bad batches actually detected = \n");
}

void removeDataSets(int data[5]){
//    int i;
//    for(i = 0; i < data[0]; i++){
//        sprintf(fileName, "ds%d.txt", i);
//        fclose(dataSets1[i]);
//        remove(fileName);
//    }
}

int main()
{
    //Declarations
    srand(time(0));

    //Read data from input files
    FILE *t1PTR, *t2PTR, *t3PTR, *t4PTR;
    int t1Data[5], t2Data[5], t3Data[5], t4Data[5];

    t1PTR = fopen("t1.txt", "r");   //Read t1.txt
    readInputFile(t1PTR, t1Data);

    t2PTR = fopen("t2.txt", "r");   //Read t2.txt
    readInputFile(t2PTR, t2Data);

    t3PTR = fopen("t3.txt", "r");   //Read t3.txt
    readInputFile(t3PTR, t3Data);

    t4PTR = fopen("t4.txt", "r");   //Read t4.txt
    readInputFile(t4PTR, t4Data);


    //generate data set from input specifications
    char fileName[12];              //MAGIC NUMBER

    //SIMULATION 1
        //Print simulation parameters
    printf("Simulation 1:\n");
    printSimParams(t1Data);
        //Generate data sets
    generateDataSets(t1Data, t1PTR, fileName);
        //Analyze data sets
    analyzeDataSets(t1Data);

    //SIMULATION 2
        //Print simulation parameters
    printf("Simulation 2:\n");
//    printSimParams(t2Data);
        //Generate data sets
//    generateDataSets(t2Data, t2PTR, fileName);
        //Analyze data sets
//    analyzeDataSets();

    //SIMULATION 3
        //Print simulation parameters
    printf("Simulation 3:\n");
//    printSimParams(t3Data);
        //Generate data sets
//    generateDataSets(t3Data, t3PTR, fileName);
        //Analyze data sets
//    analyzeDataSets();

    //SIMULATION 4
        //Print simulation parameters
    printf("Simulation 4:\n");
//    printSimParams(t4Data);
        //Generate data sets
//    generateDataSets(t4Data, t4PTR, fileName);
        //Analyze data sets
//    analyzeDataSets();

    //Part 2    :   Monte Carlo Simulation
    //read the data from readings.txt
    //compute the probability distribution
    //carry out simulation
    //predict expected bacterial reading

    //Clean up resources
    fclose(t2PTR);
    fclose(t3PTR);
    fclose(t4PTR);

    return 0;
}
