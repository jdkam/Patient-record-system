//List.cpp

#include <string>
#include <iostream>
#include "List.h"

List::List() //default constructor
{
    capacity = MAX_ELEMENTS;
}

//returns total element count currently stored in List
int List::getElementCount() const
{
    return elementCount;
}

bool List::insert(const Patient &newElement) //done
{

    if (elementCount == 0)
    { //check if list is empty
        elements[elementCount] = newElement;
        elementCount++;
    }
    else if(elementCount == capacity)
    {
        cout << "ERROR: Database is full!" << endl;
    }
    else{

        for (int i = 0; i < elementCount; i++)
        {
            if (elements[i] == newElement)
            {
                cout << "ERROR: Patient with that careCard number is already entered is already in the system!!" << endl;
                return false;
            }
        }
        //insert newElement
        elements[elementCount] = newElement;
        elementCount++;

        //sort(elements, elementCount);
        cout << "Patient Inserted Successfully" << endl;
    }
    return true;
}

// Description: Remove an element.
// Postcondition: toBeRemoved is removed and elementCount has been decremented.
bool List::remove(const Patient &toBeRemoved)
{
    //need to write
    for (int i = 0; i < elementCount; i++)
    {
        if (elements[i] == toBeRemoved)
        {
            //remove element
            elementCount--;
            //shifts everything to left by 1
            for (int k = i; k <= elementCount; k++)
            {
                this->elements[k] = this->elements[k + 1];
            }

            return true;
        }
    }
    return false;
}

void List::sort(Patient elements[], int elementCount) //DONE
{
    //bubble sort
    for (int i = 0; i < elementCount; i++)
    {
        for (int k = 0; k < elementCount - 1; k++)
        {
            if (elements[k] > elements[k + 1]) //if high > low
            {
                
                swap(&elements[k], &elements[k+1]); //swap
                
            }
        }
    }
}

void List::swap(Patient *x, Patient *y) 
{

    Patient temp = *x; 
    *x = *y;           
    *y = temp;         
}

// Description: Search for target element.
//              Returns a pointer to the element if found,
//              otherwise, returns NULL.

Patient *List::search(const Patient &target)
{

    for (int i = 0; i < elementCount; i++)
    {
        if (elements[i] == target)
        {
            cout << "Found Patient in system with following information: " << endl;
            return &(elements[i]);
        }
    }
    return NULL;
}

//Descripton: Removes all elements by setting elementCount to 0
void List::removeAll()
{
    cout << "remove all complete" << endl;
    elementCount = 0;
}

//prints all elements in the list
void List::printAll()
{
    sort(elements, elementCount);
    cout << "********Printing Patient List********\n\n";
    for (int i = 0; i < elementCount; i++)
    {
        cout << elements[i];
    }
    cout << endl;
}