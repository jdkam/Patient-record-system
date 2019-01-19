/*
 * Patient.cpp
 * 
 * Class Description: Models a walk-in clinic patient.
 * Class Invariant: Each patient has a unique care card number.
 *                  This care card number must have 10 digits.
 *                  This care card number cannot be modified. 
 *
 * Author: Jordan
 * Date: Jan 16, 2019
 */

// You can add #include statements if you wish.
#include <iostream>
#include <string>
#include "Patient.h"

// Default Constructor
// Description: Create a patient with a care card number of "0000000000". 
// Postcondition: All data members set to "To be entered", 
//                except the care card number which is set to "0000000000".       
Patient::Patient() : careCard("0000000000") {

}

// Parameterized Constructor
// Description: Create a patient with the given care card number.
// Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
//                All other data members set to "To be entered".
Patient::Patient(string aCareCard) {

	if ((aCareCard.length()) < 10 || (aCareCard.length()) > 10){
	careCard = "0000000000";
	cout << "ERROR: INVALID CARECARD LENGTH!" <<endl;
	}
	else{
		careCard = aCareCard;
	}
}

// Getters and setters -> You need to implement these methods.

//return the patient's address
string Patient::getAddress() const
{
    return address;
}

//returns the patient's carecard number
string Patient::getCareCard() const{
    return careCard;
}

//returns the patient's phone number
string Patient::getPhone() const{
    return phone;
}

//returns the patient's name
string Patient::getName() const{
    return name;
}

//returns the patient's email
string Patient::getEmail() const{
    return email;
}

//sets the patient's name
void Patient::setName(const string aName){
    name = aName;
}

//sets the patients address
void Patient::setAddress(const string anAddress){
    address = anAddress;
}

//sets the patient's phone number
void Patient::setPhone(const string aPhone){

	if ((aPhone.length()) < 10 || (aPhone.length()) >10){
		cout << "ERROR: PHONE NUMBER LENGTH INVALID!" <<endl;
	}
    phone = aPhone;
}

//sets the patient's email;
void Patient::setEmail(const string anEmail){
    email = anEmail;
}

// Overloaded Operators
// Description: Comparison operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if both Patient objects have the same care card number.
bool Patient::operator == (const Patient& rhs) {
	
	// Compare both Patient objects
	if (this->careCard == rhs.getCareCard() ) 
		return true;
	else 
		return false;
	
} // end of operator ==

// Description: Greater than operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if the care card number of "this" Patient object is > the care card 
//              number of "rhs" Patient object
bool Patient::operator > (const Patient & rhs) {
	
	// Compare both Patient objects
	if (this->careCard > rhs.getCareCard() ) 
		return true;
	else 
		return false;
	
} // end of operator >


// Description: Prints the content of "this".
ostream & operator<<(ostream & os, const Patient & p) {
	
// You need to complete this method.   
	     
	return os;

} // end of operator<<

// end of Patient.cpp
