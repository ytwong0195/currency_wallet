
#ifndef LINKED_STACK_H
#define LINKED_STACK_H
#include <cassert>
#include "linkedList.h"


template < class ItemType>
class LinkedStack : protected LinkedList<ItemType>
{
private:
	Node<ItemType>* topPtr; // Pointer to first node in the chain;
							// this node contains the stack�s top
public:
	// Constructors and destructor:
	LinkedStack() : topPtr(nullptr) {}; // Default constructor
	LinkedStack(const LinkedStack<ItemType>& aStack)
	{
		Node<ItemType>* origChainPtr = aStack->topPtr;
		if (origChainPtr == nullptr)
			topPtr = nullptr; // Original bag is empty
		else
		{
			// Copy first node
			topPtr = new Node<ItemType>();
			topPtr->setItem(origChainPtr->getItem());
			// Point to first node in new chain
			Node<ItemType>* newChainPtr = topPtr;
			// Copy remaining nodes
			while (origChainPtr != nullptr)
			{
				// Advance original-chain pointer
				origChainPtr = origChainPtr->getNext();
				// Get next item from original chain
				ItemType nextItem = origChainPtr->getItem();
				// Create a new node containing the next item
				Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
				// Link new node to end of new chain
				newChainPtr->setNext(newNodePtr);
				// Advance pointer to new last node
				newChainPtr = newChainPtr->getNext();
			} // end while
			newChainPtr->setNext(nullptr); // Flag end of chain
		} // end if
	}; // Copy constructor
	virtual ~LinkedStack()
	{
		while (!isEmpty())
			pop();
	}; // Destructor
							// Stack operations:
	bool isEmpty() const
	{
		return topPtr == nullptr;
	};
	bool push(const ItemType& newItem)
	{
		Node<ItemType>* newNodePtr = new Node<ItemType>(newItem, topPtr);
		topPtr = newNodePtr;
		newNodePtr = nullptr;
		(continues)
			248 CHAPTER 7 Implementations of the ADT Stack
			return true;
	};
	bool pop()
	{
		bool result = false;
		if (!isEmpty())
		{
			// Stack is not empty; delete top
			Node<ItemType>* nodeToDeletePtr = topPtr;
			topPtr = topPtr->getNext();
			// Return deleted node to system
			nodeToDeletePtr->setNext(nullptr);
			delete nodeToDeletePtr;
			nodeToDeletePtr = nullptr;
			result = true;
		} // end if
		return result;
	};
	ItemType peek() const
	{
		assert(!isEmpty()); // Enforce precondition
							// Stack is not empty; return top
		return topPtr->getItem();
	}
}; // end LinkedStack

#endif // !LINKED_STACK_H
