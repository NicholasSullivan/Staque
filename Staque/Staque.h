//
//  Staque.hpp
//  Program3Staque
//
//  Created by Nicholas Sullivan on 3/8/18.
//  Copyright © 2018 Nicholas Sullivan. All rights reserved.
//

#ifndef Staque_h
#define Staque_h

#include <stdio.h>
#include <iostream>
using namespace std;

typedef int StaqueElement; // define StaqueElement as an integer

class Staque
{
public:
	/***** Function Members *****/

	/***** Constructors *****/
	Staque();
	/*myHead is initialized to a null pointer.
	myTail is initialized to a null pointer.
	 myCount is initialized to zero.*/

	Staque(const Staque & original); // Copy constructor.

	/***** Destructor *****/
	~Staque();

	/***** Assignment *****/
	const Staque & operator= (const Staque & rightHandSide);
	/*------------------------------------------------------------------------
	 Assignment Operator
	 Precondition:  rightHandSide is the staque to be assigned and is
	 received as a const reference parameter.
	 Postcondition: The current staque becomes a copy of rightHandSide
	 and a const reference to it is returned.
	 ------------------------------------------------------------------------*/

	bool empty() const;
	//Returns true if Staque is empty and false otherwise.

	void push(const StaqueElement & value);
	//Add a value to a Staque. Adds to front if even, adds to back if odd.

	void pop();
	//Remove value (if any) at top of Staque if even, removes at back of staque if odd.

	void display(ostream & out) const;
	//Staque's contents, from top down, have been output to out.

	StaqueElement top() const;
	/*Value at top of Staque is returned, unless the Staque is
	 empty; in that case, an error message is displayed and a "garbage
	 value" is returned.*/

	StaqueElement bottom() const;
	/*Value at bottom of Staque is returned, unless the Staque is
	 empty; in that case, an error message is displayed and a "garbage
	 value" is returned.*/

private:
	/*** Node class ***/
	class Node
	{
	public:
		StaqueElement data;
		StaqueElement insertPosition;
		Node * next;
		Node * prev;
		//--- Node constructor
		Node(StaqueElement value, StaqueElement count, Node * head = 0, Node * tail = 0)
			/*A Node has been constructed with value in its data
			 part, count in its insertPosition part,
			 its next part set to head (default 0) and
			 its prev part set to tail (default 0).*/
			: data(value), insertPosition(count), next(head), prev(tail)
		{}
	};

	typedef Node * NodePointer;

	/***** Data Members *****/
	NodePointer myHead;      // pointer to head of Staque
	NodePointer myTail;      // pointer to tail of Staque
	StaqueElement myCount;   // stores input position

}; // end of class declaration


#endif /* Staque_hpp */
