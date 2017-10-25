
#ifndef STACK_IF_H
#define STACK_IF_H


template<class ItemType>
class StackInterface
{
public:
	virtual bool isEmpty() const = 0;
	virtual bool push(const ItemType& newEntry) = 0;
	virtual bool pop() = 0;
	virtual ItemType peek() const = 0;
};
#endif // !STACK_IF_H