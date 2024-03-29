//
//  main.cpp
//  Program3Staque
//
//  Created by Nicholas Sullivan on 3/8/18.
//  Copyright © 2018 Nicholas Sullivan. All rights reserved.
//

#include "Staque.h"
#include <iostream>
using namespace std;

// Function prototypes.
void contProg();
void displayAll(Staque & a, Staque & b, Staque & c);
void allEmpty(Staque & a, Staque & b, Staque & c);

int main(int argc, const char * argv[]) {

	// Declare & initialize variables.
	// The 3 input series for the 3 Staques.
	int const RASIZE = 7;
	int RA1[] = { 1, 3, 2, 4, 6, 8, 9 };
	int RA2[] = { 8, 6, 7, 5, 3, 0, 9 };
	int RA3[] = { 0, 1, 1, 2, 3, 5, 8 };

	// Output instructions.
	cout <<
		"************************************************\n"
		"*                                              *\n"
		"*     Welcome to the Staque.                   *\n"
		"*     Three Staques will be created.           *\n"
		"*     A different series of numbers will be    *\n"
		"*     input into each Staque, and each         *\n"
		"*     Staque will have their values deleted    *\n"
		"*     in different ways.                       *\n"
		"*                                              *\n"
		"************************************************\n"
		<< endl;

	contProg();

	// Create 3 Staques
	Staque staqueOne;
	Staque staqueTwo;
	Staque staqueThree;
	Staque staqueFour; // Just to test Assignment Operator.

	// Check that they're all empty.
	cout << endl;
	cout << "Three Staques created. Are they empty?" << endl;
	allEmpty(staqueOne, staqueTwo, staqueThree);

	cout << endl;
	cout << "Pushing 1, 3, 2, 4, 6, 8, 9 to Staque 1." << endl;
	cout << "Pushing 8, 6, 7, 5, 3, 0, 9 to Staque 2." << endl;
	cout << "Pushing 0, 1, 1, 2, 3, 5, 8 to Staque 3." << endl;

	// Push the 3 input sereis array values to the corresponding Staques.
	for (int i = 0; i < RASIZE; i++)
	{
		staqueOne.push(RA1[i]);
		staqueTwo.push(RA2[i]);
		staqueThree.push(RA3[i]);
	}

	// Check that they all now have values.
	cout << endl << "Are any Staques empty?" << endl;
	allEmpty(staqueOne, staqueTwo, staqueThree);

	contProg();
	cout << endl;

	// Show values of each Staque.
	displayAll(staqueOne, staqueTwo, staqueThree);

	contProg();

	// Show top and bottom values of each Staque.
	cout << endl;
	cout << "The top value in Staque 1 is: " << staqueOne.top() << endl;
	cout << "The bottom value in Staque 1 is: " << staqueOne.bottom() << endl;
	cout << "The top value in Staque 2 is: " << staqueTwo.top() << endl;
	cout << "The bottom value in Staque 2 is: " << staqueTwo.bottom() << endl;
	cout << "The top value in Staque 3 is: " << staqueThree.top() << endl;
	cout << "The bottom value in Staque 3 is: " << staqueThree.bottom() << endl;

	contProg();

	cout << endl << "Testing Assignment Operator with Staque 4 = Staque 1:" << endl;
	staqueFour = staqueOne;
	cout << "Staque 1:" << endl << "(Head)" << endl;
	staqueOne.display(cout);
	cout << "(Tail)" << endl << endl;
	cout << "Staque 4:" << endl << "(Head)" << endl;
	staqueFour.display(cout);
	cout << "(Tail)" << endl << endl;

	contProg();

	cout << "Testing Copy Constructor with a new Staque 5 copying Staque 2:" << endl;
	Staque staqueFive(staqueTwo);
	cout << "Staque 2:" << endl << "(Head)" << endl;
	staqueTwo.display(cout);
	cout << "(Tail)" << endl << endl;
	cout << "Staque 5:" << endl << "(Head)" << endl;
	staqueFive.display(cout);
	cout << "(Tail)" << endl << endl;

	contProg();

	// First removal series for Staque 1 (2 even and 1 odd number).
	cout << endl << "Popping 2 even numbers and 1 odd number from Staque 1:" << endl;
	cout << "Staque 1 is now:" << endl;
	staqueOne.pop();
	staqueOne.pop();
	staqueOne.pop();
	cout << "(Head)" << endl;
	staqueOne.display(cout);
	cout << "(Tail)" << endl;

	contProg();

	// Second removal series for Staque 2 (all odd numbers).
	cout << endl << "Popping all odd numbers from Staque 2:" << endl;
	cout << "Staque 2 is now:" << endl;
	staqueTwo.pop();
	staqueTwo.pop();
	staqueTwo.pop();
	staqueTwo.pop();
	cout << "(Head)" << endl;
	staqueTwo.display(cout);
	cout << "(Tail)" << endl;

	contProg();

	// Third removal series for Staque 3 (the last 2 even numbers added to the Staque).
	cout << endl << "Popping last 2 even numbers to be pushed from Staque 3:" << endl;
	cout << "Staque 3 is now:" << endl;
	staqueThree.pop();
	staqueThree.pop();
	staqueThree.pop();
	staqueThree.pop();
	cout << "(Head)" << endl;
	staqueThree.display(cout);
	cout << "(Tail)" << endl;
	// There were two odd value pushed to the Staque in between the last 2 even numbers that were pushed to the Staque, so in order to pop those last 2 even numbers, the odd values had to be popped as well according to LIFO.
	cout << "(3 and 5 were also popped in order to pop 2 due to LIFO rules.)" << endl;

	contProg();

	// Making sure Staques still have values.
	cout << endl << endl;
	cout << "Are any Staques empty?" << endl;
	allEmpty(staqueOne, staqueTwo, staqueThree);

	// Rechecking for new top and bottom values of each Staque.
	cout << "The top value in Staque 1 is: " << staqueOne.top() << endl;
	cout << "The bottom value in Staque 1 is: " << staqueOne.bottom() << endl;
	cout << "The top value in Staque 2 is: " << staqueTwo.top() << endl;
	cout << "The bottom value in Staque 2 is: " << staqueTwo.bottom() << endl;
	cout << "The top value in Staque 3 is: " << staqueThree.top() << endl;
	cout << "The bottom value in Staque 3 is: " << staqueThree.bottom() << endl;

	contProg();

	// Popping all of the values from Staque 1.
	cout << endl << endl;
	cout << "Popping all values from Staque 1:" << endl;
	while (!staqueOne.empty())
		staqueOne.pop();
	cout << "(Head)" << endl;
	staqueOne.display(cout);
	cout << "(Tail)" << endl;

	// Checking to make sure values can't be popped when Staque is empty.
	cout << endl << "Attempting to pop once more:" << endl;
	staqueOne.pop();

	// Showing Staque 1 is now empty.
	cout << endl << "Is Staque 1 empty?" << endl << (staqueOne.empty() ? "Yes." : "No.") << endl;

	// Showing There is no top value in Staque 1.
	cout << endl << "What is the top value of Staque 1?" << endl << staqueOne.top() << endl;

	// Showing There is no bottom value in Staque 1.
	cout << endl << "What is the bottom value of Staque 1?" << endl << staqueOne.bottom() << endl << endl;

} // End of main.


/*** Utility functions ***/

// Function to pause the program and prompt the user to continue.
void contProg()
{
	cout << endl << "Continue? Y/N" << endl;
	char cont = '\0';
	bool contP = false;

	while (!contP)
	{
		cin >> cont;
		cin.clear();
		cin.ignore(999, '\n');

		if (cont == 'Y' || cont == 'y')
		{
			contP = true;
		}
		else
		{
			cout << "Please input Y when ready." << endl;
		}
	}
}

// Calls the "display" function for all Staques at once to minimize code and maximize readability.
void displayAll(Staque & a, Staque & b, Staque & c)
{
	cout << "Displaying Staques:" << endl;
	cout << "Staque 1: " << endl;
	cout << "(Head)" << endl;
	a.display(cout);
	cout << "(Tail)" << endl;
	cout << endl << "Staque 2: " << endl;
	cout << "(Head)" << endl;
	b.display(cout);
	cout << "(Tail)" << endl;
	cout << endl << "Staque 3: " << endl;
	cout << "(Head)" << endl;
	c.display(cout);
	cout << "(Tail)" << endl;
}

// Calls the "empty" function for all Staques at once to minimize code and maximize readability.
void allEmpty(Staque & a, Staque & b, Staque & c)
{
	if (a.empty() && b.empty() && c.empty())
		cout << "All Staques are empty." << endl << endl;
	else if (a.empty() || b.empty() || c.empty())
		cout << "Some Staques are empty." << endl << endl;
	else
		cout << "No Staques are empty." << endl << endl;
}
