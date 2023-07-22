//Jared Bumgardner
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DEFAULTCOLLATZNUM 1024
#define DEFAULTTHREADS 8

int main(int argc, char* argv[]){
  //Declarations
  int i = 0;
  int numCollatz;
  int numThreads;
//  int collatzThreadsRatio;
  
  //Get user's input from command line
  numCollatz = DEFAULTCOLLATZNUM;
  numThreads = DEFAULTTHREADS;
  
  if(argc >= 2){    //collatz number provided
    numCollatz = atoi(argv[1]);
    printf("numCollatz = %d\n", numCollatz);
    
    if(argc >= 3){  //thread count provided
      numThreads = atoi(argv[2]);
      printf("numThreads = %d\n", numThreads);
    }
  }
  
  //Start threads
//  collatzThreadsRatio = numCollatz / numThreads;
//  while(i < numCollatz){
//    i = i + collatzThreadsRatio;
//    //create new thread to deal with current collatz number/range
// }
//  //print results
  
  return 0;
}
