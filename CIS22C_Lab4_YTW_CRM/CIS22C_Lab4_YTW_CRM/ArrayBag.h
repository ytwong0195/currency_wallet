#pragma once
# ifndef _ARRAY_BAG
# define _ARRAY_BAG
//# include "BagInterface.h"
template < class ItemType >
class ArrayBag
{
private:
	static const int DEFAULT_CAPACITY = 6; // Small size to test for a full bag
	ItemType* items; // Array of bag items
	int itemCount; // Current count of bag items
	int maxItems; // Max capacity of the bag
				  // Returns either the index of the element in the array items that
				  // contains the given target or -1, if the array does not contain
				  // the target.
	int getIndexOf(const ItemType& target, int searchIndex) const;
public:
	ArrayBag() {};
	~ArrayBag();
	ArrayBag(int inputSize);
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	void clear();
	bool contains(const ItemType& anEntry) const;
	int getFrequencyOf(const ItemType& anEntry, int searchIndex) const;
	int countFrequency(const ItemType& target, int searchIndex) const;
	int minIndex(ItemType[], int i, int j);
	void printOne(int index);
	void insertionSortRecursive(const ItemType arr[], int n);
	void quickSort(const ItemType arr[], int low, int high);
	ItemType partition(const ItemType arr[], int low, int high);
	void swap(ItemType* a, ItemType* b);
	void merge(ItemType arr[], int l, int m, int r);
	void mergeSort(ItemType arr[], int l, int r);

};  // end ArrayBag


template<class ItemType>
ArrayBag<ItemType>::~ArrayBag()
{
	delete[] items;
}

template<class ItemType>
void ArrayBag<ItemType>::printOne(int index)
{
	cout << index + 1 << ".\t" << items[index] << endl;
}

template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType & target, int searchIndex) const
{
	int result = -1;
	if (searchIndex < itemCount)
	{
		if (items[searchIndex] == target)
		{
			result = searchIndex;
		}
		else
		{
			result = getIndexOf(target, searchIndex + 1)
		}
	}
	return result;
}

template<class ItemType>
ArrayBag<ItemType>::ArrayBag(int inputSize)
{
	itemCount = 0;
	maxItems = inputSize;
	items = new ItemType[maxItems];
}

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType & newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
	}
	return hasRoomToAdd;
}

template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType & anEntry)
{
	int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}
	return canRemoveItem;

}

template<class ItemType>
void ArrayBag<ItemType>::clear()
{
	itemCount = 0;
}

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType & target) const
{
	bool found = false;
	int curIndex = 0;
	while (!found && (curIndex < itemCount))
	{
		if (target == items[curIndex])
		{
			found = true;
		}
		curIndex++
	}
	return found;
}

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType & anEntry, int searchIndex) const
{
	if (searchIndex < itemCount)
	{
		if (items[searchIndex] == target)
		{
			return 1 + countFrequency(target, searchIndex + 1);
		}
		else
		{
			return countFrequency(target, searchIndex + 1);
		}
	}
	else
	{
		return 0;
	}
}

template<class ItemType>
int ArrayBag<ItemType>::countFrequency(const ItemType & target, int searchIndex) const
{
	int frequency = 0;
	if (searchIndex < itemCount)
	{
		if (items[searchIndex] == target)
		{
			frequency = 1 + countFrequency(target, searchIndex + 1);
		}
		else
		{
			frequency = countFrequency(target, searchIndex + 1);
		}
	}
	return frequency;
}

template<class ItemType>
int ArrayBag<ItemType>::minIndex(ItemType a[], int i, int j) //for recursive selection 
{

	if (i == j)
	{
		return i;
	}

	int k = minIndex(items, i + 1, j);
	return (a[i] < a[k]) ? i : k;
}

template<class ItemType>
void ArrayBag<ItemType>::insertionSortRecursive(const ItemType arr[], int n)
{
	// Base case
	if (n <= 1)
		return;

	// Sort first n-1 elements
	insertionSortRecursive(arr, n - 1);

	// Insert last element at its correct position
	// in sorted array.
	int last = arr[n - 1];
	int j = n - 2;

	/* Move elements of arr[0..i-1], that are
	greater than key, to one position ahead
	of their current position */
	while (j >= 0 && arr[j] > last)
	{
		arr[j + 1] = arr[j];
		j--;
	}
	arr[j + 1] = last;
}

template<class ItemType>
void ArrayBag<ItemType>::quickSort(const ItemType arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

template<class ItemType>
ItemType ArrayBag<ItemType>::partition(const ItemType arr[], int low, int high)
{
	int pivot = arr[high];    // pivot
	int i = (low - 1);  // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (arr[j] <= pivot)
		{
			i++;    // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

template<class ItemType>
void ArrayBag<ItemType>::swap(ItemType* a, ItemType* b)
{
	ItemType t = *a;
	*a = *b;
	*b = t;
}

template<class ItemType>
void ArrayBag<ItemType>::merge(ItemType arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	ItemType L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

template<class ItemType>
void ArrayBag<ItemType>::mergeSort(ItemType arr[], int l, int r)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}
# endif