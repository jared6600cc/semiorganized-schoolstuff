/***************************************************************
  Jared Bumgardner
  symbolTable.c
  Project 1

  Implements the Symbol Table using a Hash Table.
***************************************************************/
#include "symbolTable.h"


void printSymbolTable(){}

int hashFunc(char *c){
	return 0;
}

TableEntry * newTableEntry(char *key, char *value){
	TableEntry *newEntry = (TableEntry *)malloc(sizeof(TableEntry));
	newEntry->key = (char *)malloc(strlen(key) + 1);
	newEntry->value = (char *)malloc(strlen(value) + 1);
	newEntry->type = 0;
	
	strcpy(newEntry->key, key);
	strcpy(newEntry->value, value);
	
	return newEntry;
}

// Delete table entry & free memory
void freeTableEntry(TableEntry *item){
	free(item->key);
	free(item->value);
	free(item);
}

// Handle collision in hash table
void handleCollision(HashTable *table, TableEntry *item){}

// Insert item into hash table
void insert(HashTable * table, char *key, char *value){
	// Create items
	TableEntry *item = newTableEntry(key, value);
	
	// Find index
	int index = hashFunc(value);
	TableEntry * currentItem = table->data[index];
	
	if(currentItem == NULL){
		// Key does not exist
		if(table->count == table->size){
			// Hash table is full
			// Print error on this line
			freeTableEntry(item);
			return;
		}
		
		// Insert directly
		table->data[index] = item;
		table->count++;
	} else {
		if(strcmp(currentItem->key, key) == 0){
			// Update value
			strcpy(table->data[index]->value, value);
			return;
		} else {
			// Collision
			handleCollision(table, item);
			return;
		}
	}
}

// Lookup table entry in symbol table
char * lookup(HashTable *table, char *key){
	int index = hashFunc(key);
	TableEntry *item = table->data[index];
	
	if(item != NULL){
		if(strcmp(item->key, key) == 0)
			return item->value;
	}
	return NULL;
}

// Create symbol table
HashTable * createTable(int size){
	HashTable *table = (HashTable *)malloc(sizeof(HashTable));
	table->size = size;
	table->count = 0;
	table->data = (TableEntry **)calloc(table->size,sizeof(TableEntry *));
	
	for(int i = 0; i < table->size; i++){
		table->data[i] = NULL;
	}
	
	return table;
}