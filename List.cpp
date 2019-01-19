//List.cpp

#include <string>
#include <iostream>
#include "List.h"


List::List() //default constructor
{
}

//returns total element count currently stored in List
int List::getElementCount() const
{
    return elementCount;
}

bool List::insert(const Patient &newElement) //done
{
    //need to write

    //need to check if newElement isnt already in data
    //compares this patient object with rhs patient object

    for (int i = 0; i < MAX_ELEMENTS; i++)
    {
        if (this->elements[i] == newElement)
        {
            return false;
        }
    }
    //insert newElement
    elements[elementCount] = newElement;
    elementCount++;
    return true;
}

bool List::remove(const Patient &toBeRemoved)
{
    //need to write
    for (int i = 0; i < MAX_ELEMENTS; i++)
    {
        if (this->elements[i] == toBeRemoved)
        {
            //remove element
            elementCount--;
            //shifts everything to left by 1
            for(int k=i; k<=elementCount; k++){
                this->elements[k] = this->elements[k+1];
                
            }

            return true;
        }
    }
    return false;
}

Patient* List::search(const Patient& target){

    for (int i=0; i< elementCount; i++){
        if(this->elements[i] == target)
        {
            return &(this->elements[i]);
        }
    }

    return NULL;
}



void List::removeAll()
{
    //need to write

    
}