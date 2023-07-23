/***************************************************************
  Jared Bumgardner
  symTable.c
  Project 1

  Contains symbol table logic and data.
***************************************************************/
#include "symTable.h"

struct entry table[50];     /* SYMBOL TABLE */
int currentEntry = 0;

/* insert: Adds name into Symbol Table. */
int insert(char * name, int type){
    if(lookup(name) < 0){
        // not in symbol table; inserting
        strcpy(table[currentEntry].name, name);
        table[currentEntry].tokenType = type;
        currentEntry++;
        return 1;
    } else {
        return -1;
    }
}

/* lookup: Finds name in Symbol Table. Returns type of name */
int lookup(char * name){
    // for each entry in the table, see if the name matches
    for(int i = currentEntry - 1; i >= 0; i--){
        if(strcmp(table[i].name, name) == 0){
            return table[i].tokenType;
        }
    }
    return NOT_FOUND;
}

/* initSymTable: Initializes symbol table values */
void initSymTable(){
    insert("id\0", ID);
    insert("num\0", NUM);
    insert("begin\0", BEGIN);
    insert("end\0", END);
    insert("int\0", INT);
    for(int i = 0; i < MAXLEXEMECOUNT; i++){
        idLexeme[i] = (char *)malloc(MAXIDLENGTH * sizeof(char));
        numLexeme[i] = (char *)malloc(MAXIDLENGTH * sizeof(char));
    }
}

/* printSymTable: Prints symbol table identifiers to console horizontally */
void printSymTable(){
    printf("\n***Program is legal***\n");
    printf("Symbol Table : \n");
    for(int i = 0; i < currentEntry; i++){
        printf("%s", table[i].name);
        if(i != currentEntry - 1){
            printf(", ");
        }
    }
    printf("\n");
}
