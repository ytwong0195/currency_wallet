#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "listIF.h"

template < class ItemType>
class LinkedList : public ListInterface<ItemType>
{
private:
	Node<ItemType>* headPtr; // Pointer to first node in the chain
	int itemCount; // Current count of list items
	Node<ItemType>* getNodeAt(int position) const;

public:
	LinkedList();
	LinkedList(const LinkedList<ItemType>& aList);
	virtual ~LinkedList();
	bool isEmpty() const;
	int getLength() const;
	bool insert(int newPosition, const ItemType& newEntry);
	bool remove(int position);
	void clear();
	ItemType getEntry(int position) const throw(PrecondViolatedExcep);
	void setEntry(int position, const ItemType& newEntry);
	throw (PrecondViolatedExcep);
}; // end LinkedList

#endif // !LINKEDLIST_H