//List.cpp

#include <string>
#include <iostream>
#include "List.h"

List::List()
{

}

//returns total element count currently stored in List
int List::getElementCount() const{
    return elementCount;
}

bool List::insert(const Patient& newElement){
//need to write

//need to check if newElement isnt already in data
if (Patient::operator==(newElement)){
    
}

//insert newElement
elements[elementCount] = newElement;
elementCount++;
}

bool List::remove(const Patient& toBeRemoved){
//need to write
}

void List::removeAll(){
//need to write
}