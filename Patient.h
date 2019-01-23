/*
 * Patient.h
 * 
 * Class Description: Models a walk-in clinic patient.
 * Class Invariant: Each patient has a unique care card number.
 *                  This care card number must have 10 digits.
 *                  This care card number cannot be modified. 
 *
 * Author: Jordan Kam
 * Date: Jan 16, 2019
 * last modified: Jan 22, 2019
 */

#pragma once

// You can add #include statements if you wish.
#include <string>
#include <iostream>
#include <locale>

using namespace std;

//Function for creating a new patient
//Description: Prompts user to enter patient info
//post condition: at the end, adds patient to List
void newPatient();

//Removes a patient by carecard number
//Description: Prompts user to enter carecard number, then removes that patient with that number
//post condition: at the end, shifts patient array by 1 and decreases element count by 1
void removePatient();

//Purpose: searches a patient by their carecard number
//precondition: patient must exist in list
//post condition: Patient is found and is printed to the user
void searchPatient();

//purpose: search a patient by carecard number first and then prompts the user what
//they want to change
//precondition: patient must exist in list
//post condition: attribute will be changed and change will be displayed to user
void modifyPatient();

class Patient
{

  private:
	// There are plenty of hints in the provided files to help you complete this section.
	string careCard;
	string address;
	string phone;
	string email;
	string name;

  public:
	/* 
 * You can add more methods to this public interface, 
 * but you cannot remove the methods below 
 * nor can you change their prototype.
 * 
 */

	// Default Constructor
	// Description: Create a patient with a care card number of "0000000000".
	// Postcondition: All data members set to "To be entered",
	//                except the care card number which is set to "0000000000".
	Patient();

	// Parameterized Constructor
	// Description: Create a patient with the given care card number.
	// Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
	//                All other data members set to "To be entered".
	Patient(string aCareCard);

	// Getters and setters
	// Description: Returns patient's name.
	string getName() const;

	// Description: Returns patient's address.
	string getAddress() const;

	// Description: Returns patient's phone.
	string getPhone() const;

	// Description: Returns patient's email.
	string getEmail() const;

	// Description: Returns patient's care card.
	string getCareCard() const;

	// Description: Sets the patient's name.
	void setName(const string aName);

	// Description: Sets the patient's address.
	void setAddress(const string anAddress);

	// Description: Sets the patient's phone.
	void setPhone(const string aPhone);

	// Description: Sets the patient's email.
	void setEmail(const string anEmail);

	// Overloaded Operators
	// Description: Comparison operator. Compares "this" Patient object with "rhs" Patient object.
	//              Returns true if both Patient objects have the same care card number.
	bool operator==(const Patient &rhs);

	// Description: Greater than operator. Compares "this" Patient object with "rhs" Patient object.
	//              Returns true if the care card number of "this" Patient object is > the care card
	//              number of "rhs" Patient object.
	bool operator>(const Patient &rhs);

	// Description: Prints the content of "this".
	friend ostream &operator<<(ostream &os, const Patient &p);

}; // end of Patient.h