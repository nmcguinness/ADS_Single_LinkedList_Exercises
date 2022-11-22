// SinglyLinkedList.cpp : Defines the entry point for the console application.
//

#include "SList.h"
#include "SListIterator.h"

void demoSingleLinkedList() {
	SList<int> myNumberList;

	//remember "new" in ANY language always returns address in RAM
	SList<int>* ptrList = new SList<int>();
	//ptrList->append();
	SList<int> objList = *ptrList;
	//objList.append();

	myNumberList.append(20);
	myNumberList.append(30);
	myNumberList.append(40);
	myNumberList.prepend(10);

	SListIterator<int> listIterator = myNumberList.getIterator();
	int number = listIterator.item();		//retrieve data
	listIterator.advance();					//move forward
	int nextNumber = listIterator.item();	//retrieve data
	listIterator.start();					//reset to head

	SListIterator<int> listIterator2 = myNumberList.getIterator();
	listIterator2.advance();					//move forward
	listIterator2.advance();					//move forward
	listIterator2.advance();					//move forward
	int aNumber = listIterator2.item();			//retrieve data
}

void print(SListIterator<int> start, SListIterator<int> end)
{
}

int main()
{
	demoSingleLinkedList();
}