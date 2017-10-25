
#ifndef _LIST_INTERFACE
#define _LIST_INTERFACE

template < class ItemType>
class ListInterface
{
public:
	virtual bool isEmpty() const = 0;
	virtual int getLength() const = 0;
	virtual bool insert(int newPosition, const ItemType& newEntry) = 0;
	virtual bool remove(int position) = 0;
	virtual void clear() = 0;
	virtual ItemType getEntry(int position) const = 0;
	virtual void setEntry(int position, const ItemType& newEntry) = 0;
}; // end ListInterface
#endif