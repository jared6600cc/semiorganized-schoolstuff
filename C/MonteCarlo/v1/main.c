#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


int main()
{
    //Read input files
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
    int i = 0;
    char fileName[12];              //MAGIC NUMBER
    FILE* dataSets1[t1Data[0]];

    for(i = 0; i < t1Data[0]; i++){     //Create data set files
        sprintf(fileName, "ds%d.txt", i);
        dataSets1[i] = fopen(fileName,"w+");
    }

    //Part 1b   :   Determine bad batches
    //implement monte carlo algorithm
    //read one at a time
    //sample number of items
    //report good/bad batch

    //Part 2    :   Monte Carlo Simulation
    //read the data from readings.txt
    //compute the probability distribution
    //carry out simulation
    //predict expected bacterial reading


    //Cleanup
    fclose(t1PTR);
    for(i = 0; i < t1Data[0]; i++){
        sprintf(fileName, "ds%d.txt", i);
        fclose(dataSets1[i]);
        remove(fileName);
    }

    fclose(t2PTR);

    fclose(t3PTR);

    fclose(t4PTR);

    return 0;
}
