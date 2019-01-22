//client code

#include "Patient.h"
#include "List.h"
#include <iostream>
#include <string>

using namespace std;

List myList;

int main()
{ //start of main

    string choice;
    bool done = false;

    while (done != true)
    {
        cout << "********** Welcome **********\n\n";
        cout << "[E] Enter a new Patient:" << endl
             << "[R] Remove an existing Patient" << endl
             << "[S] Search for an existing Patient" << endl
             << "[M] Modify an existing Patient" << endl
             << "[P] Print list of all Patients" << endl
             << "[A] Removes all Patients" << endl
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
        else if (choice == "A" || choice == "a")
        {
            cout << "Are you sure you want to delete all patients? (y/n)" << endl;
            cin >> choice;
            if (choice == "y")
            {
                removeAll();
            }
            //else do nothing
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

    cout << "       ************Program Ended by User************ " << endl;

} //END OF MAIN FUNCTION

void newPatient()
{
    string carecard;
    string name;
    string address;
    string email;
    string phone;

    cout << "Enter 10 digit Care Card number: " << endl;
    cin >> carecard;
    Patient p(carecard); //creates new patient object with entered carecard
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

    myList.insert(p);
    //insert patient object

    cout << "Elements in list: " << myList.getElementCount() << endl;

    //print Patient
    cout << p;
}

void removePatient()
{
    //search patient info
    //match info with object
    //remove object
}

void searchPatient()
{
    string searchCC;
    Patient *pTemp;

    //need to do first
    cout << "Enter the Patient you wish to search for by their Carecard number:" << endl;
    cin >> searchCC;

    pTemp = myList.search(searchCC);
    if (pTemp == NULL)
    {
        cout << "Could not find that patient in the system\n\n" << endl;
    }
    else
    {   

        cout << *pTemp << endl << endl;
    }

}

void modifyPatient()
{
    //need to do
}

void printList() //DONE
{
    myList.printAll();
}

void removeAll() //DONE
{
    myList.removeAll();
}