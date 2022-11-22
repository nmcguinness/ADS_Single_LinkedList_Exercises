#pragma once
#include "SListNode.h"
#include "SListIterator.h"

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
	//if iter is not valid
	if (iter.currentNode == nullptr)
		return;

	//if list is empty
	if (head == nullptr && tail == nullptr)
		return;

	//if list has one node and we are deleting it
	if (iter.currentNode == head)
	{
		//store head ptr
		SListNode<T>* toRemove = head;
		//does head have a next, if yes then set new head
		if (head->getNext() != nullptr)
		{
			head = head->getNext();
		}
		//one and only node has been removed
		else
		{
			head = tail = nullptr;
		}

		//delete the old head
		delete toRemove;
		return;
	}

	//if we are deleting any node after the head then read until the next node is the node pointed to by iter
	SListNode<T>* current = head;
	while (current->getNext() != iter.currentNode)
	{
		current = current->getNext();
	}

	//store the node to remove
	SListNode<T>* toRemove = current->getNext();

	//check if the node to remove has a next
	if (toRemove->getNext() != nullptr)
	{
		//if yes, set current to that node
		current->setNext(toRemove->getNext());
	}
	//node to remove is the last node
	else
	{
		current->setNext(nullptr);
		tail = current;
	}

	//remove the node pointed to by iter
	delete toRemove;
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
		SListNode<T>* current = head;
		head = head->getNext();
		delete current;
		if (head == nullptr)
			tail = nullptr;
	}
}

template <class T>
void SList<T>::removeTail()
{
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
		SListNode<T>* current = head;
		while (current->getNext() != tail)
		{
			current = current->getNext();
		}
		delete tail;
		tail = current;
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
		SListNode<T>* current = new SListNode<T>(data);
		current->setNext(head);
		head = current;
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