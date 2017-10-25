#pragma warning( disable : 4290 )  
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "listIF.h"
#include "PrecondViolatedExcep.h"
#include "node.h"
#include <cassert>

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
	bool isEmpty() const { return itemCount == 0;}
	int getLength() const { return itemCount ; }
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
			itemCount-- ; // Decrease count of entries
		} // end if
		return ableToRemove;
	} // end remove;
	void clear()
	{
		while (!isEmpty()) { remove(1); };
	};
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
		bool ableToSet = (position >= 1) && (position <= itemCount);
		if (ableToSet)
		{
			Node<ItemType>* myPrevNodePtr = getNodeAt(position);
			myPrevNodePtr->setItem(newEntry);
		}
		else
		{
			string message = "setEntry() called with an empty list or ";
			message = message + "invalid position.";
			throw(PrecondViolatedExcep(message));
		}
		//throw (PrecondViolatedExcep(message));
	}

	Node<ItemType>* getPointerTo(const ItemType& target) const
	{
		bool found = false;
		Node<ItemType>* currPtr = headPtr;
		while (!found && currPtr != nullptr)
		{
			if (target == currPtr->getItem())
			{
				found = true;
			}
			else
			{
				currPtr = currPtr->getNext();
			}
		}//end while
		return currPtr;
	}//end getPointerTo

	int getPosition(const ItemType& target) const
	{
		int position = 0;
		if (itemCount == 0) {
			position = 0;
			return position;
		}
		else
		{
			position = 1;
			Node<ItemType>* currPtr = headPtr;
			
			while (target != currPtr->getItem() && currPtr->getNext() != nullptr)
			{
				currPtr = currPtr->getNext();
				position++;
			}//end while
			if (target == currPtr->getItem())
			{
				return position;
			}
			else if (position==itemCount)
			{
				cout << "not found" << endl;
				position = -1;
				
			}
			
		}
		return position;
		
	}

	int contains(const ItemType& anEntry)
	{
		return (getPosition(anEntry));
	}// end contains

	bool add(const ItemType& newEntry)
	{
		Node(ItemType) * newNodePtr = new Node<ItemType>();
		newNodePtr->setItem(newEntry);
		newNodePtr->setNext(headPtr);
		headPtr = newNodePtr;
		itemCount++;
		return true;
	}
}; // end LinkedList

#endif // !LINKEDLIST_H
