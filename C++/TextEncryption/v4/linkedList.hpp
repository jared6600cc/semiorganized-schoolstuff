#ifndef LINKED_LIST_H
#define LINKED_LIST_H


#include <iostream>


namespace L
{
	struct node 
	{
		std::string data;
		node* next;
	};

	class linkedList
	{
	public:
		// Constructor(s)
		linkedList();
		// Getter(s)
		node* getHead();
		// Method(s)
		void insertFront(std::string s);
		bool find(std::string findMe);
	private:
		// Attribute(s)
		node* head;
		node* tail;
	};
}


#endif /* LINKED_LIST_H*/