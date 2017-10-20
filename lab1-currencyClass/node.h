#pragma once
#ifndef _NODE
#define _NODE

template < class ItemType>
class Node
{
private:
	ItemType item; // A data item
	Node<ItemType>* next; // Pointer to next node
public:
	Node() : headPtr(nullptr), itemCount(0) {};
	Node(const ItemType& anItem) : item(anItem), next(nullptr) {};
	Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) :
		item(anItem), next(nextNodePtr) {};
	void setItem(const ItemType& anItem) {item = anItem;}
	void setNext(Node<ItemType>* nextNodePtr) { next = nextNodePtr; };
	ItemType getItem() const { return item; }
	Node<ItemType>* getNext() const { return next };
}; // end Node

#endif
