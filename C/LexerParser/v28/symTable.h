/******************************************************************************
  Jared Bumgardner
  symTable.h
  Project 1

  Defines keywords, table entries, and function prototypes for symbol table.
******************************************************************************/
#ifndef SYMTABLEHEADER
#define SYMTABLEHEADER

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXIDLENGTH 20      // Maximum character length for Identifiers
#define TABLESIZE 100		// Symbol Table size

#define ID 300				// alphanumeric value
#define NUM 301				// numeric value
#define BEGIN 400			// program start keyword
#define END 401				// program end keyword
#define NOT_FOUND -1		// missing id from table
#define DONE -100           // returned on end of file

struct entry{
    char name[MAXIDLENGTH];
    int tokenType;
};

int lookup(char * name);
void insert(char * name, int type);
void initSymTable();
void printSymTable();

#endif // SYMTABLEHEADER
