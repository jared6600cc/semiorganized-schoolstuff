#include "hashTable.hpp"
#include <iostream>
#include <fstream>
#include <sstream>


using namespace H;
using namespace std;


H::hashTable::hashTable() 
{
	arrayBuckets = new linkedList * [size];
	for (int i = 0; i < size; i++) 
	{
		arrayBuckets[i] = new linkedList;
	}
}


int H::hashTable::getSize()
{
	return size;
}


int H::hashTable::hashFunc(string hashMe)
{
	int hashedIndex = 0;
	string alphabet = "abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < hashMe.length(); i++) 
	{
		for (int j = 0; j < 26; j++) 
		{
			if ((tolower(hashMe[i])) == alphabet[j]) 
			{
				hashedIndex += j;
			}
		}
	}


	return hashedIndex % size;
}

void H::hashTable::build(std::string fileName)
{
	string bufferLine;
	ifstream inFileEncrypted;
	inFileEncrypted.open(fileName, ios::in);
	if (inFileEncrypted.is_open()) 
	{
		while (getline(inFileEncrypted, bufferLine)) 
		{
			stringstream bufferStream(bufferLine);
			getline(bufferStream, bufferLine, ' ');		// get userID
			int hashedIndex = hashFunc(bufferLine);
			getline(bufferStream, bufferLine, ' ');		// get encrypted password
			arrayBuckets[hashedIndex]->insertFront(bufferLine);
		}
	}
	else { cout << "Error opening encrypteddata.txt to build hash table"; }
}

bool H::hashTable::find(std::string findUserName)
{
	int hashIndex = hashFunc(findUserName);
	bool result = false;
	if (arrayBuckets[hashIndex]->getHead() == NULL)
		return result;
	result = arrayBuckets[hashIndex]->find(findUserName);
	return result;
}
