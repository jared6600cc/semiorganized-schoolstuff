#include "linkedList.hpp"
#include <iostream>

using namespace L;
using namespace std;

L::linkedList::linkedList()
{
	head = NULL;
	tail = NULL;
}

node* L::linkedList::getHead()
{
	return head;
}

void L::linkedList::insertFront(string s)
{
	struct node n;
	n.data = s;
	n.next = head;
	head = &n;
}

bool L::linkedList::find(string findMe)
{
	bool foundMe = false;
	node* position;
	position = getHead();
//	while (position->next != NULL) 
//	{
//		// DEBUG: ERROR IS HERE
//		position = position->next;
//	}
	return foundMe;
}
