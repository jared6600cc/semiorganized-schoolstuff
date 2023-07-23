/******************************************************************************
  Jared Bumgardner
  symTable.h
  Project 1

  Defines keywords, table entries, and function prototypes for symbol table.
******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#ifndef SYMTABLE_H
#define SYMTABLE_H

#define MAXIDLENGTH 32      // Maximum character length for Identifiers
#define TABLESIZE 100		// Symbol Table size
#define MAXLEXEMECOUNT 32   // maximum number of lexemes allowed

#define ID 300				// alphanumeric value
#define NUM 301				// numeric value
#define INT 302             // keyword for variable declarations
#define BEGIN 400			// program start keyword
#define END 401				// program end keyword
#define NOT_FOUND -1		// missing id from table
#define DONE -100           // returned on end of file

char * idLexeme[MAXLEXEMECOUNT];
char * numLexeme[MAXLEXEMECOUNT];
int idLexemeCount, numLexemeCount;

struct entry{
    char name[MAXIDLENGTH];
    int tokenType;
};

int lookup(char * name);
int insert(char * name, int type);
void initSymTable();
void printSymTable();

#endif // SYMTABLE_H
