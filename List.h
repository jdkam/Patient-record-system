/*
 * List.h
 * 
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - (What other characteristic does our List have?)
 *
 * Author: Jordan
 * Date:
 */

#pragma once

// You can add #include statements if you wish.
#include <string>
#include <iostream>
#include "Patient.h"

using namespace std;


class List  {

private:

/* 
 * You can add more attributes to this class, 
 * but you cannot remove the attributes below 
 * nor can you change them.
 */

	static const int MAX_ELEMENTS = 5; // Small capacity so can test when data collection becomes full
	                                   // ***As we are testing the code of our assignment, we can  
	                                   //    change the value given to this constant.***
	Patient elements[MAX_ELEMENTS];    // Data structure with capacity of MAX_ELEMENTS
	int elementCount = 0;                  // Current element count in element array
	int capacity;                  	    // Actual maximum capacity of element array   

public:

/* 
 * You can add more methods to this interface, 
 * but you cannot remove the methods below 
 * nor can you change their prototype.
 * 
 */

	// Default constructor
	List();

	// Description: Returns the total element count currently stored in List.
	int getElementCount() const;

	// Description: Insert an element.
	// Precondition: newElement must not already be in data collection.  
	// Postcondition: newElement inserted and elementCount has been incremented.   
	bool insert(const Patient& newElement);

	// Description: Remove an element. 
	// Postcondition: toBeRemoved is removed and elementCount has been decremented.	
	bool remove( const Patient& toBeRemoved );


	//Description: Bubble sorts patients by carecard
	void sort(Patient elements[], int elementCount);

	void swap(Patient *x, Patient *y);

	//Patient modSearch(const Patient &target);


	//uses the osstream overload to print list
	void printAll();
	
	// Description: Remove all elements.
	void removeAll();
   
	// Description: Search for target element.
	//              Returns a pointer to the element if found,
	//              otherwise, returns NULL.
	Patient* search(const Patient& target);

	void swap(int *x, int *y);
   

}; // end List.h