/*****************************************************************************
 * AUTHOR 	  		: Nick Reardon
 * Assignment #4	: Deque To Queue
 * CLASS			: CS1D
 * SECTION			: MW - 2:30p
 * DUE DATE			: 02 / 10 / 20
 *****************************************************************************/
#ifndef _VECTORHEAP_H_
#define _VECTORHEAP_H_
#include <exception>
#include <vector>
#include "Except.h"

enum ERROR_TYPE
{
	DEFUALT,
	FULL,
	EMPTY,
	OUT_OF_RANGE
};


template <class Type>
class VectorMaxHeap
{
private:
	std::vector<Type> heap;

protected:
	void sort()
	{

	}

public:

	VectorMaxHeap<Type>(const int newCapacity = 8)
	{
		heap.reserve(newCapacity);
	}

	//VectorHeap<Type>(const VectorHeap<Type>& otherDeque);

	~VectorMaxHeap();

	void destroy()
	{
		heap.clear();
	}

	bool empty() const	{ return heap.empty(); }

	int size() const	{ return heap.size(); }

	void insert(const Type& element)
	{
		heap.push_back(element);

		int index = heap.size();

		if (index % 2 == 0)
		{

		}
		while()
	}

	void remove();


	Type max() const;

	//void printAll(std::ostream& output) const;

};


#endif //!_VECTORHEAP_H_
