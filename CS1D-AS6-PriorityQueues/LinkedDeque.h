/*****************************************************************************
 * AUTHOR 	  		: Nick Reardon
 * Assignment #4	: Deque To Queue
 * CLASS			: CS1D
 * SECTION			: MW - 2:30p
 * DUE DATE			: 02 / 10 / 20
 *****************************************************************************/
#ifndef _LINKEDDEQUE_H_
#define _LINKEDDEQUE_H_
#include <exception>
#include <sstream>
#include "Except.h"

enum ERROR_TYPE
{
	DEFUALT,
	FULL,
	EMPTY,
	OUT_OF_RANGE
};

template <class Type>
struct Node
{
	Type value;

	Node<Type>* prev;
	Node<Type>* next;

	Node<Type>(const Type& newValue, Node<Type>* prevNode, Node<Type>* nextNode)
	{
		value = newValue;

		prev = prevNode;
		next = nextNode;
	}

};

template <class Type>
class LinkedDeque
{
private:
	Node<Type>* head;
	Node<Type>* tail;

	int capacity;
	int currentSize;


protected:

public:

	LinkedDeque<Type>(const int newCapacity = 32);

	LinkedDeque<Type>(const LinkedDeque<Type>& otherDeque);

	~LinkedDeque();

	void destroy();

	bool empty() const;
	bool full() const;
	int size() const;

	void insertBefore(const Type& newItem, const int index);
	void insertAfter(const Type& newItem, const int index);

	void insertFront(const Type& newItem);
	void insertBack(const Type& newItem);

	void eraseFront();
	void eraseBack();


	Type front() const;
	Type back() const;

	void printAll(std::ostream& output) const;

};


template<class Type>
inline LinkedDeque<Type>::LinkedDeque(const int newCapacity)
{
	head = nullptr;
	tail = nullptr;

	capacity = newCapacity;
	currentSize = 0;
}

template<class Type>
inline LinkedDeque<Type>::LinkedDeque(const LinkedDeque<Type>& otherDeque)
{
	capacity = otherDeque.capacity;
	currentSize = 0;

	head = nullptr;
	tail = nullptr;

	for (Node<Type>* temp = otherDeque.head; temp != nullptr; temp = temp->next)
	{
		insertBack(temp->value);
	}
}


template<class Type>
inline LinkedDeque<Type>::~LinkedDeque()
{
	destroy();
}

template<class Type>
inline bool LinkedDeque<Type>::empty() const
{
	bool value = (currentSize == 0 && head == nullptr && tail == nullptr);

	return value;
}

template<class Type>
inline bool LinkedDeque<Type>::full() const
{
	bool value = (currentSize == capacity);

	return value;
}

template<class Type>
inline void LinkedDeque<Type>::destroy()
{
	for (Node<Type>* temp = head; temp != nullptr; )
	{
		Node<Type>* hold = temp;
		temp = temp->next;
		delete hold;
	}

	head = nullptr;
	tail = nullptr;

}

template<class Type>
inline void LinkedDeque<Type>::insertBefore(const Type& newItem, const int index)
{
	if (empty())
	{
		throw Except("container is empty", EMPTY, 5);
	}
	else if (full())
	{
		throw Except("container is full", FULL, 5);
	}
	else
	{
		if (index <= (size() - 1 / 2))
		{
			Node<Type>* ptr = head;
			for (int i = 0; i < index; i++)
			{
				ptr = ptr->next;
			}
			Node<Type>* temp = new Node<Type>(newItem, nullptr, nullptr);

			temp->prev = ptr->prev;
			temp->next = ptr;

			ptr->prev = temp;
			temp->prev->next = temp;

			temp = nullptr;
			ptr = nullptr;

			currentSize++;
		}
		else
		{
			Node<Type>* ptr = head;
			for (int i = size() - 1; i >= size() - 1 - index; i--)
			{
				ptr = ptr->next;
			}
			Node<Type>* temp = new Node<Type>(newItem, nullptr, nullptr);

			temp->prev = ptr->prev;
			temp->next = ptr;

			ptr->prev = temp;
			temp->prev->next = temp;

			temp = nullptr;
			ptr = nullptr;

			currentSize++;
		}
	}

}

template<class Type>
inline void LinkedDeque<Type>::insertAfter(const Type& newItem, const int index)
{
	if (empty())
	{
		throw Except("container is empty", EMPTY, 5);
	}
	else if (full())
	{
		throw Except("container is full", FULL, 5);
	}
	else
	{
		if (index <= (size() - 1 / 2))
		{
			Node<Type>* ptr = head;
			for (int i = 1; i <= index; i++)
			{
				ptr = ptr->next;
			}
			Node<Type>* temp = new Node<Type>(newItem, nullptr, nullptr);

			temp->next = ptr->next;
			ptr->next = temp;

			temp->prev = ptr;
			temp->next->prev = temp;

			temp = nullptr;
			ptr = nullptr;

			currentSize++;
		}
		else
		{
			Node<Type>* ptr = head;
			for (int i = size() - 1; i >= size() - 1 - index; i--)
			{
				ptr = ptr->next;
			}
			Node<Type>* temp = new Node<Type>(newItem, nullptr, nullptr);

			temp->next = ptr->next;
			ptr->next = temp;

			temp->prev = ptr;
			temp->next->prev = temp;

			temp = nullptr;
			ptr = nullptr;

			currentSize++;
		}
	}

}

template<class Type>
inline void LinkedDeque<Type>::insertFront(const Type& newItem)
{

	if (!full())
	{
		if (head == 0)
		{
			head = new Node<Type>(newItem, nullptr, nullptr);
			tail = head;
		}
		else
		{
			Node<Type>* temp = new Node<Type>(newItem, nullptr, nullptr);

			head->prev = temp;

			temp->next = head;
			temp->prev = nullptr;

			head = temp;

			temp = nullptr;
		}
		currentSize++;

	}
	else
	{
		throw Except("container is full", FULL, 5);
	}
}

template<class Type>
inline void LinkedDeque<Type>::insertBack(const Type& newItem)
{

	if (!full())
	{
		if (head == 0)
		{
			head = new Node<Type>(newItem, nullptr, nullptr);
			tail = head;
		}
		else
		{
			Node<Type>* temp = new Node<Type>(newItem, nullptr, nullptr);

			tail->next = temp;

			temp->prev = tail;
			temp->next = nullptr;

			tail = temp;

			temp = nullptr;
		}
		currentSize++;

	}
	else
	{
		throw Except("container is full", FULL, 5);
	}

}

template<class Type>
inline void LinkedDeque<Type>::eraseFront()
{

	if (!empty())
	{
		if (head == tail)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			Node<Type>* temp = head;
			head = head->next;
			head->prev = nullptr;
			delete temp;
		}
		currentSize--;

	}
	else
	{
		throw Except("container is empty", EMPTY, 5);
	}

}

template<class Type>
inline void LinkedDeque<Type>::eraseBack()
{
	if (!empty())
	{
		if (head == tail)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			Node<Type>* temp = tail;
			tail = tail->prev;
			tail->next = nullptr;
			delete temp;
		}
		currentSize--;

	}
	else
	{
		throw Except("container is empty", EMPTY, 5);
	}

}

template<class Type>
inline int LinkedDeque<Type>::size() const
{
	return currentSize;
}


template<class Type>
inline Type LinkedDeque<Type>::front() const
{
	return head->value;
}

template<class Type>
inline Type LinkedDeque<Type>::back() const
{
	return tail->value;
}

template<class Type>
inline void LinkedDeque<Type>::printAll(std::ostream& output) const
{
	for (Node<Type>* temp = head; temp != nullptr; temp = temp->next)
	{
		output << temp->value << '\n';
	}
}



template<class Type>
class LinkedQueue
{
private:
	LinkedDeque<Type> deque;

protected:

public:

	LinkedQueue<Type>(const int newCapacity = 32);

	LinkedQueue<Type>(LinkedQueue<Type>& otherQueue);
	LinkedQueue<Type>(LinkedDeque<Type>& otherDeque);

	~LinkedQueue();

	void destroy();

	bool empty() const;
	bool full() const;
	int size() const;

	void enqueue(const Type& newItem);
	void dequeue();

	Type front() const;
	Type back() const;

	void printAll(std::ostream& output) const;

};



#endif // !_LINKEDDEQUE_H_

template<class Type>
inline LinkedQueue<Type>::LinkedQueue(const int newCapacity) :
	deque(newCapacity)
{

}

template<class Type>
inline LinkedQueue<Type>::LinkedQueue(LinkedQueue<Type>& otherQueue) :
	deque(otherQueue)
{

}

template<class Type>
inline LinkedQueue<Type>::LinkedQueue(LinkedDeque<Type>& otherDeque) :
	deque(otherDeque)
{

}
template<class Type>
inline void LinkedQueue<Type>::destroy()
{
	deque.destroy();
}

template<class Type>
inline LinkedQueue<Type>::~LinkedQueue()
{
	deque.destroy();
}

template<class Type>
inline bool LinkedQueue<Type>::empty() const
{
	return deque.empty();
}

template<class Type>
inline bool LinkedQueue<Type>::full() const
{
	return deque.full();
}

template<class Type>
inline int LinkedQueue<Type>::size() const
{
	return deque.size();
}

template<class Type>
inline void LinkedQueue<Type>::enqueue(const Type& newItem)
{
	deque.insertBack(newItem);
}

template<class Type>
inline void LinkedQueue<Type>::dequeue()
{
	deque.eraseFront();
}

template<class Type>
inline Type LinkedQueue<Type>::front() const
{
	return deque.front();
}

template<class Type>
inline Type LinkedQueue<Type>::back() const
{
	return deque.back();
}

template<class Type>
inline void LinkedQueue<Type>::printAll(std::ostream& output) const
{
	deque.printAll(output);
}



template<class Type>
void PrintWithLabel(const std::string& label, const LinkedDeque<Type> &container, std::ostream& output)
{
	output << '\n' << label << '\n';

	if (container.empty())
	{
		output << "Container is empty \n\n";
		
	}
	else
	{
		container.printAll(output);
		output << '\n';
	}
}

template<class Type>
void PrintWithLabel(const std::string& label, const LinkedQueue<Type>& container, std::ostream& output)
{
	output << '\n' << label << '\n';

	if (container.empty())
	{
		output << "Container is empty \n\n";

	}
	else
	{
		container.printAll(output);
		output << '\n';
	}
}