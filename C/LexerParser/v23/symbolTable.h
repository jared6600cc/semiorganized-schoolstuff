/***************************************************************
  Jared Bumgardner
  symbolTable.h
  Project 1

  Contains prototypes & declarations for the symbol table.
***************************************************************/
#include <stdlib.h>
#include <string.h>


// An entry in the Symbol Table
typedef struct TableEntry TableEntry;
struct TableEntry{
	char *key;
	char *value;
	int type;
};


// Symbol Table
typedef struct HashTable HashTable;
struct HashTable{
	TableEntry** data;
	int size;
	int count;
};


//...
void printSymbolTable();
int hashFunc(char *c);
void insert(HashTable * table, char *key, char *value);
char * lookup(HashTable *table, char *key);
HashTable * createTable(int size);