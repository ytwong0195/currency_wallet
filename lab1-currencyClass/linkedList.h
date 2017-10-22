#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "listIF.h"
#include "PrecondViolatedExcep.h"

template < class ItemType>
class LinkedList : public ListInterface<ItemType>
{
private:
	Node<ItemType>* headPtr; // Pointer to first node in the chain
	int itemCount; // Current count of list items
	Node<ItemType>* getNodeAt(int position) const
	{
		// Debugging check of precondition
		assert((position >= 1) && (position <= itemCount));
		// Count from the beginning of the chain
		Node<ItemType>* curPtr = headPtr;
		for (int skip = 1; skip < position; skip++)
			curPtr = curPtr->getNext();
		return curPtr;
	};

public:
	LinkedList() : headPtr(nullptr), itemCount(0) {};
	LinkedList(const LinkedList<ItemType>& aList){ headPtr = copyChain(aList.headPtr);};
	virtual ~LinkedList()
	{
		clear();
	};
	bool isEmpty() const { return itemCount == 1;}
	int getLength() const { return itemCount - 1; }
	bool insert(int newPosition, const ItemType& newEntry)
	{
		bool ableToInsert = (newPosition >= 1) &&
			(newPosition <= itemCount + 1);
		if (ableToInsert)
		{
			// Create a new node containing the new entry
			Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
			// Attach new node to chain
			if (newPosition == 1)
			{
				// Insert new node at beginning of chain
				newNodePtr->setNext(headPtr);
				headPtr = newNodePtr;
			}
			else
			{
				// Find node that will be before new node
				Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);
				// Insert new node after node to which prevPtr points
				newNodePtr->setNext(prevPtr->getNext());
				prevPtr->setNext(newNodePtr);
			} // end if
			itemCount++; // Increase count of entries
		} // end if
		return ableToInsert;
	} // end insert;
	bool remove(int position)
	{
		bool ableToRemove = (position >= 1) && (position <= itemCount);
		if (ableToRemove)
		{
			Node<ItemType>* curPtr = nullptr;
			if (position == 1)
			{
				// Remove the first node in the chain
				curPtr = headPtr; // Save pointer to node
				headPtr = headPtr->getNext();
			}
			else
			{
				// Find node that is before the one to delete
				Node<ItemType>* prevPtr = getNodeAt(position - 1);
				// Point to node to delete
				curPtr = prevPtr->getNext();
				// Disconnect indicated node from chain by connecting the
				// prior node with the one after
				prevPtr->setNext(curPtr->getNext());
			} // end if
			  // Return node to system
			curPtr->setNext(nullptr);
			delete curPtr;
			curPtr = nullptr;
			itemCount– - ; // Decrease count of entries
		} // end if
		return ableToRemove;
	} // end remove;
	void clear()
	{
		while (!isEmpty()) { remove(2); };
	};\
	ItemType getEntry(int position) const throw(PrecondViolatedExcep)
	{
		// Enforce precondition
		bool ableToGet = (position >= 1) && (position <= itemCount);
		if (ableToGet)
		{
			Node<ItemType>* nodePtr = getNodeAt(position);
			return nodePtr->getItem();
		}
		else
		{
			string message = "getEntry() called with an empty list or ";
			message = message + "invalid position.";
			throw(PrecondViolatedExcep(message));
		} // end if
	};
	void setEntry(int position, const ItemType& newEntry)
	{
		bool ableToSet = (position > 1) && (position <= itemCount);
		if (ableToSet)
		{
			Node* myPrevNodePtr = getNodeAt(position);
			myPrevNodePtr->setItem(newEntry);
		}
		else
		{
			string message = "setEntry() called with an empty list or ";
			message = message + "invalid position.";
			throw(PrecondViolatedExcep(message));
		}
	throw (PrecondViolatedExcep);
}; // end LinkedList

#endif // !LINKEDLIST_H
