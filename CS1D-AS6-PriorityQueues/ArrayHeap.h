/*****************************************************************************
 * AUTHOR 	  		: Nick Reardon
 * Assignment #4	: Deque To Queue
 * CLASS			: CS1D
 * SECTION			: MW - 2:30p
 * DUE DATE			: 02 / 10 / 20
 *****************************************************************************/
#ifndef _ARRAYHEAP_H_
#define _ARRAYHEAP_H_
#include <exception>
#include "Except.h"

enum ERROR_TYPE
{
	DEFUALT,
	FULL,
	EMPTY,
	OUT_OF_RANGE
};

template <typename Type, typename Key>
struct heapMember
{
	Type value;
	Key key;

	heapMember(const Type& newValue, const Key& newKey)
	{
		value = newValue;
		key = newKey;
	}

	heapMember() {}

	void swap(heapMember& other)
	{
		Key tempKey;
		Type tempType;

		tempKey = other.key;
		tempType = other.value;

		other.key = this->key;
		other.value = this->value;

		this->key = tempKey;
		this->value = tempType;

		
	}

	inline bool operator< (const heapMember& other)
	{
		return (this->key < other.key);
	}

	inline bool operator> (const heapMember& other)
	{
		return (this->key > other.key);
	}

	inline void operator= (const heapMember& other)
	{
		this->key = other.key;
		this->value = other.value;
	}
};

template <class Type, class Key>
class ArrayMaxHeap
{
private:
	heapMember<Type, Key>* heap;

	int currentSize;

	int capacity;

protected:
	void sort()
	{
		int index = 1;

		int swapIndex;

		while ( (2 * index < currentSize) && 
			((heap[index].key < heap[2 * index].key) || (heap[index].key < heap[2 * index + 1].key)) )
		{
			if (heap[2 * index].key > heap[2 * index + 1].key)
			{
				swapIndex = 2 * index;
			}
			else
			{
				swapIndex = 2 * index + 1;
			}

			heap[index].swap(heap[swapIndex]);

			index = swapIndex;
		}
	}



public:

	ArrayMaxHeap<Type,Key>(const int newCapacity = 32)
	{
		heap = new heapMember<Type, Key>[newCapacity];
		currentSize = 0;
		capacity = newCapacity;
	}

	//VectorHeap<Type>(const VectorHeap<Type>& otherDeque);

	~ArrayMaxHeap()
	{
		delete[] heap;
	}

	bool empty() const { return currentSize == 0; }

	bool full() const { return currentSize == capacity; }

	int size() const { return size; }

	void insert(const Type& element, const Key& newKey)
	{
		if (full())
		{
			throw Except("container is full", FULL, 5);
		}

		currentSize++;

		heap[currentSize].value = element;
		heap[currentSize].key = newKey;


		int index = currentSize;

		while ( (heap[index].key > heap[index / 2].key) && ((index / 2) != 0) )
		{
			heap[index].swap(heap[index / 2]);

			index /= 2;

		}

	}

	void remove()
	{
		if (empty())
		{
			throw(Except("Cannot remove - heap is empty", EMPTY, 5));
		}

		heap[1] = heap[currentSize]; 
		currentSize--;
		sort();
	}



	Type max() const
	{
		Type temp = heap[1].value;
		return temp;
	}

	void printAll(std::ostream& output) const
	{
		if (empty())
		{
			throw(Except("Cannot print - heap is empty", EMPTY, 5));
		}

		int current = 0;
		int levelSize = 1;

		for (int i = 1; i < currentSize; i++)
		{
			output << heap[i].value << '(' << heap[i].key << ')' << "  ";

			current++;

			if (current == levelSize)
			{
				current = 0;

				levelSize = levelSize * 2;

				output << '\n';
			}
		}

		output << "\n\n";
	}

};


#endif //!_ARRAYHEAP_H_