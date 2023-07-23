/***************************************************************
  Jared Bumgardner
  errorReporter.h
  Project 2

  Contains custom exit routine.
***************************************************************/
#ifndef ERRORREPORTER_H
#define ERRORREPORTER_H

void exitWithError(int errorLineNo, char * errorMessage){
    printf("\n***Program is illegal***");
    printf("\nLine %d contains error: %s.\n", errorLineNo - 1, errorMessage);
    exit(-1);
}

#endif // ERRORREPORTER_H
