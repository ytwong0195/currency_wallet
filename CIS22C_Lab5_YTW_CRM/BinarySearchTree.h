#pragma warning( disable : 4290 )  
#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "BinaryNodeTree.h"
#include "NotFoundException.h"
#include "PrecondViolatedExcep.h"

template <class ItemType>
class BinarySearchTree : public BinaryNodeTree<ItemType>
{
private:
	std::string fname;
	std::string lname;
	std::string bday;
	BinaryNode<ItemType>* leftPtr;
	BinaryNode<ItemType>* rightPtr;
	BinaryNode<ItemType>* rootPtr;
protected:
	//------------------------------------------------------------
	// Protected Utility Methods Section:
	// Recursive helper methods for the public methods.
	//------------------------------------------------------------
	// Recursively finds where the given node should be placed and
	// inserts it in a leaf at that point.
	BinaryNode<ItemType>* insertInorder(BinaryNode<ItemType>* subTreePtr,
										BinaryNode<ItemType>* newNode);
	// Removes the given target value from the tree while maintaining a
	// binary search tree.
	BinaryNode<ItemType>* removeValue(BinaryNode<ItemType>* subTreePtr,
		const ItemType target,
		bool& success);
	// Removes a given node from a tree while maintaining a
	// binary search tree.
	BinaryNode<ItemType>* removeNode(BinaryNode<ItemType>* nodePtr);
	// Removes the leftmost node in the left subtree of the node
	// pointed to by nodePtr.
	// Sets inorderSuccessor to the value in this node.
	// Returns a pointer to the revised subtree.
	BinaryNode<ItemType>* removeLeftmostNode(
		BinaryNode<ItemType>* subTreePtr, ItemType& inorderSuccessor);
	// Returns a pointer to the node containing the given value,
	// or nullptr if not found.
	BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* treePtr,
		const ItemType& target) const;
public:
	//------------------------------------------------------------
	// Constructor and Destructor Section.
	//------------------------------------------------------------
	BinarySearchTree();
	BinarySearchTree(const ItemType& rootItem);
	BinarySearchTree(const BinarySearchTree<ItemType>& tree);
	virtual ~BinarySearchTree();
	//------------------------------------------------------------
	// Public Methods Section.
	//------------------------------------------------------------
	bool isEmpty() const;
	int getHeight() const;
	int getNumberOfNodes() const;
	ItemType getRootData() const throw (PrecondViolatedExcep);
	void setRootData(const ItemType& newData) const
		throw (PrecondViolatedExcep);
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	void clear();
	ItemType getEntry(const ItemType& anEntry) const
		throw (NotFoundException);
	bool contains(const ItemType& anEntry) const;
	bool replace(const ItemType& anEntry, const ItemType& replaceEntry);
	//------------------------------------------------------------
	// Public Traversals Section.
	//------------------------------------------------------------
	void preorderTraverse(void visit(ItemType&)) const;
	void inorderTraverse(void visit(ItemType&)) const;
	void postorderTraverse(void visit(ItemType&)) const;
	//------------------------------------------------------------
	// Overloaded Operator Section.
	//------------------------------------------------------------
	BinarySearchTree<ItemType>&
		operator=(const BinarySearchTree<ItemType>& rightHandSide);
}; // end BinarySearchTree

template <class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::
insertInorder(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNode)
{
	if (subTreePtr == 0)
	{
		return newNode;
	}
	else
	{
		if (subTreePtr->getItem() > newNode->getItem())
		{
			subTreePtr->setLeftChildPtr(insertInorder(subTreePtr->getLeftChildPtr(), newNode));
		}
		else
		{
			subTreePtr->setRightChildPtr(insertInorder(subTreePtr->getRightChildPtr(), newNode));
		}
		return subTreePtr;
	}
}

template <class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::
removeValue(BinaryNode<ItemType>* subTreePtr, const ItemType target, bool& success)
{
	if (subTreePtr == nullptr)
	{
		success = false;
		return nullptr;
	}
	else if (subTreePtr->getItem() == target)
	{
		subTreePtr = removeNode(subTreePtr);
		success = true;
		return subTreePtr;
	}
	else
	{
		if (subTreePtr->getItem() > target)
		{
			subTreePtr->setLeftChildPtr(removeValue(subTreePtr->getLeftChildPtr(), target, success));
		}
		else
		{
			subTreePtr->setRightChildPtr(removeValue(subTreePtr->getRightChildPtr(), target, success));
		}
	}
	return subTreePtr;
}

template <class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::
removeNode(BinaryNode<ItemType>* nodePtr)
{
	if (nodePtr->isLeaf())
	{
		delete nodePtr;
		return (nodePtr = nullptr);
	}
	else if (nodePtr->getLeftChildPtr() == nullptr)
	{
		BinaryNode<ItemType>* nodeToConnectPtr = nodePtr->getRightChildPtr();
		delete nodePtr;
		nodePtr = nullptr;
		return nodeToConnectPtr;
	}
	else if (nodePtr->getRightChildPtr() == nullptr)
	{
		BinaryNode<ItemType>* nodeToConnectPtr = nodePtr->getLeftChildPtr();
		delete nodePtr;
		nodePtr = nullptr;
		return nodeToConnectPtr;
	}
	else
	{
		ItemType newNodeValue;
		nodePtr->setRightChildPtr(removeLeftmostNode(nodePtr->getRightChildPtr(), newNodeValue));
			nodePtr->setItem(newNodeValue);
			return nodePtr;
	}
}

template <class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::
removeLeftmostNode(BinaryNode<ItemType>* subTreePtr, ItemType& inorderSuccessor)
{
	if (subTreePtr->getLeftChildPtr() == nullptr)
	{
		inorderSuccessor = subTreePtr->getItem();
		return removeNode(subTreePtr);
	}
	else
	{
		subTreePtr->setLeftChildPtr(removeLeftmostNode(subTreePtr->getLeftChildPtr(), inorderSuccessor));
		return subTreePtr;
	}
}

template <class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::findNode(BinaryNode<ItemType>* treePtr,
	const ItemType& target) const
{
	if (treePtr == nullptr)
	{
		return nullptr;
	}
	else if (treePtr->getItem() == target)
	{
		return treePtr;
	}
	else if (treePtr->getItem() > target)
	{
		return findNode(treePtr->getLeftChildPtr(), target);
	}
	else
	{
		return findNode(treePtr->getRightChildPtr(), target);
	}
}

template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() : rootPtr(nullptr)
{
}

template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem)
{
	rootPtr = new BinaryNode<ItemType>(rootItem, nullptr, nullptr);
} // end constructor

template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& tree)
{
	rootPtr = this->copyTree(tree.rootPtr());
}

template <class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree()
{
	this->destroyTree(rootPtr);
}

template <class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const
{
	return rootPtr == nullptr;
}

template <class ItemType>
int BinarySearchTree<ItemType>::getHeight() const
{
	return this->getHeightHelper(rootPtr);
}

template <class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const
{
	return this->getNumberOfNodesHelper(rootPtr);
}

template <class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const throw (PrecondViolatedExcep)
{
	if (isEmpty())
		throw PrecondViolatedExcep("getRootData() called empty tree.");
	return rootPtr->getItem();
}

template <class ItemType>
void BinarySearchTree<ItemType>::
setRootData(const ItemType& newData) const throw (PrecondViolatedExcep)
{
	throw PrecondViolatedExcep("Cannot change root value in a BST.");
}

template < class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newData)
{
	BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newData);
	rootPtr = insertInorder(rootPtr, newNodePtr);
	return true;
} // end add

template <class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType& data)
{
	bool isSuccessful = false;
	rootPtr = removeValue(rootPtr, data, isSuccessful);
	return isSuccessful;
}

template <class ItemType>
void BinarySearchTree<ItemType>::clear()
{
	this->destroyTree(rootPtr);
	rootPtr = 0;
}

template <class ItemType>
ItemType BinarySearchTree<ItemType>::
getEntry(const ItemType& anEntry) const throw (NotFoundException)
{
	
	BinaryNode<ItemType>* nodeWithEntry = findNode(rootPtr, anEntry);
	if (nodeWithEntry == nullptr)
	{
		throw NotFoundException("Entry not found.");
	}
	else
	{
		return nodeWithEntry->getItem();
	}
}

template <class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& anEntry) const
{
	return findNode(rootPtr, anEntry);
}

template<class ItemType>
bool BinarySearchTree<ItemType>::replace(const ItemType& anEntry, const ItemType& replaceEntry)
{
	bool item = contains(anEntry);
	if (item == 1)
	{
		bool exist;
		BinaryNode<ItemType>* newNodePtr = findNode(rootPtr, anEntry, exist);
		newNodePtr->setItem(replaceEntry);
		return true;
	}
	else 
	{
		cout << "Does not exist.";
		return false;

	}
}

template <class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse(void visit(ItemType&)) const
{
	this->preorder(visit, rootPtr);
}

template <class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
{
	this->inorder(visit, rootPtr);
}

template <class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse(void visit(ItemType&)) const
{
	this->postorder(visit, rootPtr);
}

template <class ItemType>
BinarySearchTree<ItemType>& BinarySearchTree<ItemType>::
operator=(const BinarySearchTree<ItemType>& rightHandSide)
{
	if (!isEmpty())
	{
		clear();
		this = copyTree(&rightHandSide);
		return *this;
	}
}

#endif