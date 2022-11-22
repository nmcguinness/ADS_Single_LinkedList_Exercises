#pragma once
#include "SListIterator.h"
#include "SListNode.h"

template <class T>
class SList
{
public:
	SListNode<T>* head, * tail;
	SList();
	void append(T data);
	void prepend(T data);
	void removeHead();
	void removeTail();
	void remove(SListIterator<T> iter);
	SListIterator<T> getIterator();
	void insert(SListIterator<T> iter, T data);
	~SList();
};
template <class T>
void SList<T>::remove(SListIterator<T> iter)
{
}
template <class T>
void SList<T>::insert(SListIterator<T> iter, T data)
{
	if (iter.list != this)
	{
		return;
	}
	if (!iter.isValid() || head == nullptr)
	{
		append(data);
	}
	else
	{
		iter.currentNode->insertAfter(data);
		if (iter.currentNode == tail)
			tail = iter.currentNode->getNext();
	}
}

template <class T>
SListIterator<T> SList<T>::getIterator()
{
	return SListIterator<T>(this, head);
}
template <class T>
void SList<T>::removeHead()
{
	if (head == nullptr)
	{
		return;
	}
	else
	{
		SListNode<T>* temp = head;
		head = head->getNext();
		delete temp;
		if (head == nullptr)
			tail = nullptr;
	}
}

template <class T>
void SList<T>::removeTail()
{
	//no node
	//1 node
	//N nodes

	if (head == nullptr)
	{
		return;
	}
	if (head == tail)
	{
		delete head;
		head = tail = nullptr;
	}
	else
	{
		SListNode<T>* temp = head;
		while (temp->getNext() != tail)
		{
			temp = temp->getNext();
		}
		delete tail;
		tail = temp;
		tail->setNext(nullptr);
	}
}
template <class T>
SList<T>::SList()
{
	head = tail = nullptr;
}

template <class T>
void SList<T>::append(T data)
{
	if (head == nullptr)
	{
		head = tail = new SListNode<T>(data);
	}
	else
	{
		tail->insertAfter(data);
		tail = tail->getNext();
	}
}
template <class T>
void SList<T>::prepend(T data)
{
	if (head == nullptr)
	{
		head = tail = new SListNode<T>(data);
	}
	else
	{
		SListNode<T>* temp = new SListNode<T>(data);
		temp->setNext(head);
		head = temp;
	}
}

template <class T>
SList<T>::~SList()
{
	SListNode<T>* current = head;
	while (current != 0) {
		SListNode<T>* next = current->getNext();
		delete current;
		current = next;
	}
	head = 0;
}