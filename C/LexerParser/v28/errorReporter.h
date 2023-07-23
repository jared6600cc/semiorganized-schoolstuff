#ifndef ERRORREPORTERHEADER
#define ERRORREPORTERHEADER

int lineno;

void exitWithError(int errorLineNo, char * errorMessage){
    printf("\n***Program is illegal***");
    printf("\nLine %d contains error: %s.\n", errorLineNo, errorMessage);
    exit(-1);
}

#endif // ERRORREPORTERHEADER
