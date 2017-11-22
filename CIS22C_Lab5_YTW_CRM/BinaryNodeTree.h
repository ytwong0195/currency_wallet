#pragma once
#ifndef _BINARY_NODE_TREE
#define _BINARY_NODE_TREE

#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "PrecondViolatedExcep.h"
#include "NotFoundException.h"

template < class ItemType>
class BinaryNodeTree : public BinaryTreeInterface<ItemType>
{
private:
	BinaryNode<ItemType>* rootPtr;
protected:
	//------------------------------------------------------------
	// Protected Utility Methods Section:
	// Recursive helper methods for the public methods.
	//------------------------------------------------------------
	int getHeightHelper(BinaryNode<ItemType>* subTreePtr) const;
	int getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const;
	// Recursively deletes all nodes from the tree.
	void destroyTree(BinaryNode<ItemType>* subTreePtr);
	// Recursively adds a new node to the tree in a left/right fashion to
	// keep the tree balanced.
	BinaryNode<ItemType>* balancedAdd(BinaryNode<ItemType>* subTreePtr,
		BinaryNode<ItemType>* newNodePtr);
	// Removes the target value from the tree by calling moveValuesUpTree
	// to overwrite value with value from child.
	BinaryNode<ItemType>* removeValue(BinaryNode<ItemType>* subTreePtr,
		const ItemType target, bool& success);
	// Copies values up the tree to overwrite value in current node until
	// a leaf is reached; the leaf is then removed, since its value is
	// stored in the parent.
	BinaryNode<ItemType>* moveValuesUpTree(BinaryNode<ItemType>* subTreePtr);
	// Recursively searches for target value in the tree by using a
	// preorder traversal.
	BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* treePtr,
		const ItemType& target,
		bool& success) const;
	// Copies the tree rooted at treePtr and returns a pointer to
	// the copy.
	BinaryNode<ItemType>*
		copyTree(const BinaryNode<ItemType>* treePtr) const;
	// Recursive traversal helper methods:
	void preorder(void visit(ItemType&),
		BinaryNode<ItemType>* treePtr) const;
	void inorder(void visit(ItemType&),
		BinaryNode<ItemType>* treePtr) const;
	void postorder(void visit(ItemType&),
		BinaryNode<ItemType>* treePtr) const;
public:
	//------------------------------------------------------------
	// Constructor and Destructor Section.
	//------------------------------------------------------------
	BinaryNodeTree();
	BinaryNodeTree(const ItemType& rootItem);
	BinaryNodeTree(const ItemType& rootItem,
		const BinaryNodeTree<ItemType>* leftTreePtr,
		const BinaryNodeTree<ItemType>* rightTreePtr);
	 tree);
	virtual ~BinaryNodeTree();
	//------------------------------------------------BinaryNodeTree(const BinaryNodeTree<ItemType>&------------
	// Public BinaryTreeInterface Methods Section.
	//------------------------------------------------------------
	bool isEmpty() const;
	int getHeight() const;
	int getNumberOfNodes() const;
	ItemType getRootData() const throw (PrecondViolatedExcep);
	void setRootData(const ItemType& newData);
	bool add(const ItemType& newData); // Adds a node
	bool remove(const ItemType& data); // Removes a node
	void clear();
	ItemType getEntry(const ItemType& anEntry) const
		throw (NotFoundException);
	bool contains(const ItemType& anEntry) const;
	//------------------------------------------------------------
	// Public Traversals Section.
	//------------------------------------------------------------
	void preorderTraverse(void visit(ItemType&)) const;
	void inorderTraverse(void visit(ItemType&)) const;
	void postorderTraverse(void visit(ItemType&)) const;
	//------------------------------------------------------------
	// Overloaded Operator Section.
	//------------------------------------------------------------
	BinaryNodeTree& operator=(const BinaryNodeTree& rightHandSide);
}; // end BinaryNodeTree

#endif

template <class ItemType>
int BinaryNodeTree<ItemType>::
getHeightHelper(BinaryNode<ItemType>* subTreePtr) const
{
	if (subTreePtr == nullptr)
		return 0;
	else
		return 1 + max(getHeightHelper(subTreePtr->getLeftChildPtr()),
			getHeightHelper(subTreePtr->getRightChildPtr()));
}

template <class ItemType>
int BinaryNodeTree<ItemType>::
getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const
{
	if (subTreePtr == nullptr)
		return 0;
	else
		return 1 + max(getNumberOfNodesHelper(subTreePtr->getLeftChildPtr()),
			getNumberOfNodesHelper(subTreePtr->getRightChildPtr()));
}

template <class ItemType>
void BinaryNodeTree<ItemType>::
destroyTree(BinaryNode<ItemType>* subTreePtr)
{
	if (subTreePtr != nullptr)
	{
		destroyTree(subTreePtr->getLeftChildPtr());
		destroyTree(subTreePtr->getRightChildPtr());
		delete subTreePtr;
	} // end if
} // end destroyTree

template <class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::
balancedAdd(BinaryNode<ItemType>* subTreePtr,
	BinaryNode<ItemType>* newNodePtr)
{
	if (subTreePtr == nullptr)
		return newNodePtr;
	else
	{
		BinaryNode<ItemType>* leftPtr = subTreePtr->getLeftChildPtr();
		BinaryNode<ItemType>* rightPtr = subTreePtr->getRightChildPtr();
		if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr))
		{
			rightPtr = balancedAdd(rightPtr, newNodePtr);
			subTreePtr->setRightChildPtr(rightPtr);
		}
		else
		{
			leftPtr = balancedAdd(leftPtr, newNodePtr);
			subTreePtr->setLeftChildPtr(leftPtr);
		} // end if
		return subTreePtr;
	} // end if
} // end balancedAdd

template <class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::
removeValue(BinaryNode<ItemType>* subTreePtr,
	const ItemType target, bool& success)
{
	if (subTreePtr == nullptr)
	{
		success = false
			return nullptr
	}
	else if (subTreePtr->getItem() == target)
	{
		// Item is in the root of some subtree
		subTreePtr = removeNode(subTreePtr) // Remove the item
			success = true
			return subTreePtr
	}
	else if (subTreePtr->getItem() > target)
	{
		// Search the left subtree
		tempPtr = removeValue(subTreePtr->getLeftChildPtr(), target, success)
			subTreePtr->setLeftChildPtr(tempPtr)
			return subTreePtr
	}
	else
	{
		// Search the right subtree
		tempPtr = removeValue(subTreePtr->getRightChildPtr(), target, success)
			subTreePtr->setRightChildPtr(tempPtr)
			return subTreePtr
	}

}

template <class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::
moveValuesUpTree(BinaryNode<ItemType>* subTreePtr)
{
	BinaryNode<ItemType>* leftPtr = subTreePtr->getLeftChildPtr();
	BinaryNode<ItemType>* rightPtr = subTreePtr->getRightChildPtr();
	int leftHeight = getHeightHelper(leftPtr);
	int rightHeight = getHeightHelper(rightPtr);

	if (leftHeight > rightHeight)
	{
		subTreePtr->setItem(leftPTr->getItem());
		leftPtr = moveValueUpTree(leftPtr);
		subTreePtr->setLeftChildPtr(leftPtr);
		return subTreePtr;
	}
	else
	{
		if (rightPtr != nullptr)
		{
			subTreePtr->setItem(rightPtr->getItem());
			rightPtr = moveValuesUpTree(rightPtr);
			subTreePtr->setRightChildPtr(rightPtr);
			return subTreePtr;
		}
		else
		{
			delete subTreePtr;
			return nullptr;
		}
	}
}

//may have to come back to this to correct
template <class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::
findNode(BinaryNode<ItemType>* treePtr,
	const ItemType& target, bool& success) const
{
	if (subTreePtr == nullptr)
		return nullptr // Not found
	else if (subTreePtr->getItem() == target)
		return subTreePtr; // Found
	else if (subTreePtr->getItem() > target)
		// Search left subtree
		return findNode(subTreePtr->getLeftChildPtr(), target)
	else
		// Search right subtree
		return findNode(subTreePtr->getRightChildPtr(), target)
}

template <class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::
copyTree(const BinaryNode<ItemType>* treePtr) const
{
	BinaryNode<ItemType>* newTreePtr = nullptr;
	// Copy tree nodes during a preorder traversal
	if (treePtr != nullptr)
	{
		// Copy node
		newTreePtr = new BinaryNode<ItemType>(treePtr->getItem(),
			nullptr, nullptr);
		newTreePtr->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
		newTreePtr->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));
	} // end if
	  // Else tree is empty (newTreePtr is nullptr)
	return newTreePtr;
}

template <class ItemType>
void BinaryNodeTree<ItemType>::
preorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
	if (treePtr != nullptr)
	{
		ItemType theItem = treePtr->getItem();
		visit(theItem);
		preorder(visit, treePtr->getLeftChildPtr());
		preoder(visit, treePtr->getRightChildPtr());
	}
}

template <class ItemType>
void BinaryNodeTree<ItemType>::
inorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
	if (treePtr != nullptr)
	{
		inorder(visit, treePtr->getLeftChildPtr());
		ItemType theItem = treePtr->getItem();
		visit(theItem);
		inorder(visit, treePtr->getRightChildPtr());
	}
}

template <class ItemType>
void BinaryNodeTree<ItemType>::
postorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
	if (treePtr != nullptr)
	{
		postorder(visit, treePtr->getLeftChildPtr());
		postorder(visit, treePtr->getRightChildPtr());
		ItemType theItem = treePtr->getItem();
		visit(theItem);

	}
}

template <class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree() : rootPtr(nullptr)
{
} // end default constructor

template <class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem)
{
	rootPtr = new BinaryNode<ItemType>(rootItem, nullptr, nullptr);
} // end constructor

template <class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem,
	const BinaryNodeTree<ItemType>* leftTreePtr,
	const BinaryNodeTree<ItemType>* rightTreePtr)
{
	rootPtr = new BinaryNode<ItemType>(rootItem,
		copyTree(leftTreePtr->rootPtr()),
		copyTree(rightTreePtr->rootPtr());
}

template <class ItemType>
BinaryNodeTree<ItemType>::
BinaryNodeTree(const BinaryNodeTree<ItemType>& treePtr)
{
	rootPtr = copyTree(treePtr.rootPtr());
}

template <class ItemType>
BinaryNodeTree<ItemType>::~BinaryNodeTree()
{
	destroyTree(rootPtr);
}

template <class ItemType>
bool BinaryNodeTree<ItemType>::isEmpty() const
{
	return rootPtr = nullptr;
}

template <class ItemType>
int BinaryNodeTree<ItemType>::getHeight() const
{
	return getHeightHelper(rootPtr);
}

template <class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodes() const
{
	return getNumberOfNodesHelper(rootPtr);
}

template <class ItemType>
ItemType BinaryNodeTree<ItemType>::getRootData() const throw (PrecondViolatedExcep)
{
	if (isEmpty())
		throw PrecondViolatedExcep("getRootData() called empty tree.");
	return rootPtr->getItem();
}

template <class ItemType>
void BinaryNodeTree<ItemType>::setRootData(const ItemType& newData)
{
	if (isEmpty())
	{
		rootPtr = new BinaryNode(newData, nullptr, nullptr);
	}
	else
	{
		rootPtr->setItem(newData);
	}
}

template < class ItemType>
bool BinaryNodeTree<ItemType>::add(const ItemType& newData)
{
	BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newData);
	rootPtr = insertInorder(rootPtr, newNodePtr);
	return true;
} // end add

template <class ItemType>
bool BinaryNodeTree<ItemType>::remove(const ItemType& data)
{
	bool isSuccessful = false;
	rootPtr = removeValue(rootPtr, data, isSuccessful);
	return isSuccessful;
}

template <class ItemType>
void BinaryNodeTree<ItemType>::clear()
{
	destroyTree(rootPtr);
	rootPtr = nullptr;
}

template <class ItemType>
ItemType BinaryNodeTree<ItemType>::
getEntry(const ItemType& anEntry) const throw (NotFoundException)
{
	bool isSuccessful = false;
	BinaryNode<ItemType>* binaryNodePtr = findNode(rootPtr, anEntry, isSuccessful);
	if (isSuccessful)
	{
		return binaryNodePtr->getItem();
	}
	else
	{
		throw NotFoundException("Entry not found.");
	}
}

template <class ItemType>
bool BinaryNodeTree<ItemType>::contains(const ItemType& anEntry) const
{
	bool isSuccessful = false;
	findNode(rootPtr, anEntry, isSuccessful);
	return isSuccessful;
}

template <class ItemType>
void BinaryNodeTree<ItemType>::preorderTraverse(void visit(ItemType&)) const
{
	preorder(visit, rootPtr);
}

template <class ItemType>
void BinaryNodeTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
{
	inorder(visit, rootPtr);
}

template <class ItemType>
void BinaryNodeTree<ItemType>::postorderTraverse(void visit(ItemType&)) const
{
	postorder(visit, rootPtr);
}

template <class ItemType>
BinaryNodeTree& BinaryNodeTree<ItemType>::operator=(const BinaryNodeTree& rightHandSide)
{
	if (!isEmpty())
	{
		clear();
		this = copyTree(&rightHandSide);
		return *this;
	}
}
