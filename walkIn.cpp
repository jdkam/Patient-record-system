//client code

#include "Patient.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{ //start of main
    string choice;
    bool done = false;

while(done!=true){
    cout << "[E] Enter a new Patient:" << endl
         << "[R] Remove an existing Patient" << endl
         << "[S] Search for an existing Patient" << endl
         << "[M] Modify an existing Patient" << endl
         << "[P] Print list of all Patients"
         << "[X] Exit Program" << endl;


    cin >> choice;

    if (choice == "E" || choice == "e")
    {
        newPatient();
    }
    else if (choice == "R" || choice == "r")
    {
        removePatient();
    }
    else if (choice == "S" || choice == "s")
    {
        searchPatient();
    }
    else if (choice == "M" || choice == "m")
    {
        modifyPatient();
    }
    else if (choice == "P" || choice == "p")
    {
        printList();
    }
    else if (choice == "X" || choice == "x")
    {
        done = true;
        break;
    }
    else
    {
        cout << "Option not recognized.. Please try again." << endl;
    }

}

    cout << "       ************FINISHED EXECUTABLE************ " << endl;

} //END OF MAIN FUNCTION

void newPatient()
{
    string cc;
    string name;
    string address;
    string email;
    string phone;

    cout << "Enter 10 digit Care Card number: " << endl;
    cin >> cc;
    Patient p(cc); //creates new patient object with entered carecard
    cout << "CareCard set to: " << p.getCareCard() << "\n\n";

    //grab name
    cout << "Enter Patient's Name: ";
    cin.ignore(1000, '\n'); //fixes a getline error where cin is leaving the carriage return in the buffer
    getline(cin, name);
    p.setName(name); //set patients name to entered name
    cout << "Patient's name set to: " << p.getName() << "\n\n";

    //grab address
    cout << "Enter Patient's address: ";
    getline(cin, address);
    p.setAddress(address);
    cout << "Address set to: " << p.getAddress() << "\n\n";

    //grab phone
    while ((phone.length()) != 10)
    { //check if phone number is correct length
        cout << "Enter Patient's phone number: ";
        getline(cin, phone);

        if ((phone.length()) < 10 || (phone.length()) > 10)
        {
            cout << "ERROR: PHONE NUMBER LENGTH INVALID!" << endl;
        }
    }

    p.setPhone(phone);
    cout << "Phone number set to: " << p.getPhone() << "\n\n";

    //grab email
    cout << "Enter Patient's email: ";
    getline(cin, email);
    p.setEmail(email);
    cout << "Email set to: " << p.getEmail() << "\n\n";

    //insert patient object
    //delete patient object
}

void removePatient()
{
    //search patient info
    //match info with object
    //remove object
}

void searchPatient()
{
}

void modifyPatient()
{
}

void printList()
{
}