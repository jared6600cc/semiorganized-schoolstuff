#ifndef HASH_TABLE_H
#define HASH_TABLE_H


#include "linkedList.hpp"
#include <iostream>

using namespace L;


namespace H
{
	class hashTable
	{
	public:
		// Attribute(s)
		int size = 1024;
		linkedList** arrayBuckets;
		// Constructor(s)
		hashTable();
		// Getter(s)
		int getSize();
		// Method(s)
		int hashFunc(std::string hashMe);
		void build(std::string fileName);
		bool find(std::string findUserName);		
	};
}


#endif /* HASH_TABLE_H*/