#ifndef ERRORREPORTER_H
#define ERRORREPORTER_H

void exitWithError(int errorLineNo, char * errorMessage){
    printf("\n***Program is illegal***");
    printf("\nLine %d contains error: %s.\n", errorLineNo, errorMessage);
    exit(-1);
}

#endif // ERRORREPORTER_H
