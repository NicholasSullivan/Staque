//
//  Staque.cpp
//  Program3Staque
//
//  Created by Nicholas Sullivan on 3/8/18.
//  Copyright © 2018 Nicholas Sullivan. All rights reserved.
//

#include "Staque.h"
#include <new>
using namespace std;

//--- Definition of Staque constructor
Staque::Staque()
	: myHead(0), myTail(0), myCount(0) // Creates Staque with myHead, myTail, and myCount all getting 0.
{}

//--- Definition of Staque copy constructor
Staque::Staque(const Staque & original)
{
	myHead = 0;
	myTail = 0;
	myCount = 0;

	if (!original.empty())
	{
		// Copy first node
		myCount++; // Increase myCount for new node.
		myHead = new Staque::Node(original.top(), original.myHead->insertPosition); // Create a new node with original's first value and insertPosition.
		myTail = myHead; // Since this is the first node, the tail is equal to the head.

		// Set pointers to run through the Staques’ linked lists
		Staque::NodePointer lastPtr = myHead, prevPtr = 0,
			origPtr = original.myHead->next;
		lastPtr->prev = 0;

		while (origPtr != 0)
		{
			myCount++; // Increment myCount for each new node.
			lastPtr->next = new Staque::Node(origPtr->data, origPtr->insertPosition); // new node with orig's data and insertPosition.
			prevPtr = lastPtr; // keep track of lastPtr to add to the next node's prev.
			lastPtr = lastPtr->next; // move lastPtr to the new node.
			lastPtr->prev = prevPtr; // set new node's prev to prevPtr.
			origPtr = origPtr->next; // move origPtr to next node in original Staque.
			lastPtr->next = 0; // new node's next gets zero until a new node is added to the staque.
		}
	}
}

//--- Definition of Staque destructor
Staque::~Staque()
{
	// Set pointers to run through the Staque.
	Staque::NodePointer currPtr = myHead,  // node to be deallocated
		nextPtr;          // its successor
	while (currPtr != 0)
	{
		nextPtr = currPtr->next;
		delete currPtr;
		currPtr = nextPtr;
	}
}

//--- Definition of assignment operator
const Staque & Staque::operator=(const Staque & rightHandSide)
{
	if (this != &rightHandSide)         // check that not st = st
	{
		this->~Staque();                  // destroy current linked list trying to be created.
		if (rightHandSide.empty())       // empty Staque
			myHead = 0;
		else
		{                                // copy rightHandSide's list
			// Copy first node
			myCount++; // Increase myCount for new node.
			myHead = new Staque::Node(rightHandSide.top(), rightHandSide.myHead->insertPosition); // Create a new node with original's first value and insertPosition.
			myTail = myHead; // Since this is the first node, the tail is equal to the head.

			// Set pointers to run through the Staques’ linked lists
			Staque::NodePointer lastPtr = myHead, prevPtr = 0,
				rhsPtr = rightHandSide.myHead->next;
			lastPtr->prev = 0;

			while (rhsPtr != 0)
			{
				myCount++; // Increment myCount for each new node.
				lastPtr->next = new Staque::Node(rhsPtr->data, rhsPtr->insertPosition); // new node with orig's data and insertPosition.
				prevPtr = lastPtr; // keep track of lastPtr to add to the next node's prev.
				lastPtr = lastPtr->next; // move lastPtr to the new node.
				lastPtr->prev = prevPtr; // set new node's prev to prevPtr.
				rhsPtr = rhsPtr->next; // move origPtr to next node in original Staque.
				lastPtr->next = 0; // new node's next gets zero until a new node is added to the staque.
			}
		} // end else.
	}
	return *this;
}

//--- Definition of empty()
bool Staque::empty() const
{
	return (myCount == 0);
	// returns true if empty, false otherwise.
}

//--- Definition of push()
void Staque::push(const StaqueElement & value)
{
	Staque::NodePointer currPtr = myHead; // stores current head to later add link to new node.

	// if adding 1st node, doesn't matter if even or odd.
	if (myCount == 0)
	{
		myCount++; // increase count with new node creation first.
		myHead = new Staque::Node(value, myCount, myHead, myTail); // first new node becomes new head and new tail.
		myTail = myHead; // head is also tail.
	}
	else // when adding nodes after one is already added.
	{
		// if value is even, add to front of staque.
		if (value % 2 == 0)
		{
			myCount++; // increase count with new node creation first.
			myHead = new Staque::Node(value, myCount, myHead, 0); // new even node's next is set to old head node, prev set to 0, becomes new head.
			currPtr->prev = myHead; // old head node's prev gets new node.
		}
		else // if value is odd, add to back of staque.
		{
			myCount++; // increase count with new node creation first.
			myTail->next = new Staque::Node(value, myCount, 0, myTail); // new odd node gets 0 for next, gets old tail as prev, becomes old tail's next.
			myTail = myTail->next; // new odd node becomes new tail.
		}
	}
}

//--- Definition of pop()
void Staque::pop()
{
	if (!empty())
	{
		Staque::NodePointer ptr; // creates a temp pointer.

		// checks the head to see if it was last in, if so, pops it.
		if (myHead->insertPosition == myCount)
		{
			ptr = myHead;
			myHead = myHead->next;
			if (myHead != 0)
				myHead->prev = 0;
			myCount--;
			delete ptr;
		}
		// checks the tail to see if it was last in, if so, pops it.
		else if (myTail->insertPosition == myCount)
		{
			ptr = myTail;
			myTail = myTail->prev;
			myTail->next = 0;
			myCount--;
			delete ptr;
		}
		else
			cerr << "*** Error. Value not at head or tail. ***" << endl;
	}
	else
		cerr << "*** Staque is empty -- can't remove a value ***" << endl;
}

//--- Definition of display()
void Staque::display(ostream & out) const
{
	Staque::NodePointer ptr; // create walking stick
	for (ptr = myHead; ptr != 0; ptr = ptr->next) // walk through and output data value.
		out << ptr->data << endl;
}

//--- Definition of top()
StaqueElement Staque::top() const
{
	if (!empty())
		return (myHead->data); // if staque isn't empty, return myHead's data.
	else // else return garbage.
	{
		cerr << "*** Staque is empty "
			" -- returning garbage ***\n";
		StaqueElement * temp = new(StaqueElement);
		StaqueElement garbage = *temp;     // "Garbage" value
		delete temp;
		return garbage;
	}
}

//--- Definition of bottom()
StaqueElement Staque::bottom() const
{
	if (!empty())
		return (myTail->data); // if staque isn't empty, return myTail's data.
	else // else return garbage.
	{
		cerr << "*** Staque is empty "
			" -- returning garbage ***\n";
		StaqueElement * temp = new(StaqueElement);
		StaqueElement garbage = *temp;     // "Garbage" value
		delete temp;
		return garbage;
	}
}
