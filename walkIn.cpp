/*
 * walkIn.cpp
 * 
 * Class Description: Client code that interfaces with user
 * prompts user for an action
 * Keep prompting user until user decides to exit
 *
 * Author: Jordan Kam
 * Date created: Jan 16, 2019
 * Last modified Jan 22, 2019
 */

#include "Patient.h"
#include "List.h"
#include <iostream>
#include <string>

using namespace std;

List myList;

//start of main
//purpose: Prompts the user to perform an action
//post condition performs an action and returns to the main menu
int main()
{

    string choice;
    bool done = false;

    while (done != true)
    {
        cout << "********** Welcome **********\n\n";
        cout << "Type in an option below:\n";
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
            myList.printAll();
        }
        else if (choice == "A" || choice == "a")
        {
            cout << "Are you sure you want to delete all patients? (y/n)" << endl;
            cin >> choice;
            if (choice == "y")
            {
                myList.removeAll();
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

//Function for creating a new patient
//Description: Prompts user to enter patient info
//post condition: at the end, adds patient to List
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
    if(carecard.length() > 10 || carecard.length()<10)
    {
        myList.insert(p);
        return;
    }

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

//Removes a patient by carecard number
//Description: Prompts user to enter carecard number, then removes that patient with that number
//post condition: at the end, shifts patient array by 1 and decreases element count by 1
void removePatient()
{
    string removeCC;

    cout << "Enter the patient you want to remove by their carecard number: " << endl;
    cin >> removeCC;

    if (myList.remove(removeCC))
    {
        cout << "Patient removed successfully!" << endl
             << endl;
    }
    else
    {
        cout << "Could not find patient in system\n\n";
    }
}

//Purpose: searches a patient by their carecard number
//precondition: patient must exist in list
//post condition: Patient is found and is printed to the user
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
        cout << "Could not find that patient in the system\n\n"
             << endl;
    }
    else
    {

        cout << *pTemp << endl
             << endl;
    }
}

//purpose: search a patient by carecard number first and then prompts the user what
//they want to change
//precondition: patient must exist in list
//post condition: attribute will be changed and change will be displayed to user
void modifyPatient()
{
    Patient *modifyP;
    Patient newP;
    string searchCC;
    string choice;
    bool done = false;
    string name;
    string address;
    string phone;
    string email;

    cout << "Enter the carecard of the patient you wish to modify\n";
    cin >> searchCC;

    modifyP = myList.search(searchCC);
    if (modifyP == NULL)
    {
        cout << "Could not find that patient in the system\n\n"
             << endl;
    }
    else
    {
        cout << *modifyP << " Is the p that you searched" << endl;
        while (done != true)
        {
            cout << "Type what you wish to modify: \n";
            cout << "[N] Name\n[A] Address\n[P] Phone\n[E] Email\n[X] Exit\n\n";
            cin >> choice;

            if (choice == "N" || choice == "n")
            {
                //cout << modifyP->getCareCard() << endl;

                cout << "Type a new name: " << endl;
                cin.ignore(1000, '\n'); //fixes a getline error where cin is leaving the carriage return in the buffe
                getline(cin, name);

                modifyP->setName(name);

                cout << modifyP->getName() << " has been set to new name\n";
            }
            else if (choice == "A" || choice == "a")
            {
                cout << "Type a new address: " << endl;
                cin.ignore(1000, '\n'); //fixes a getline error where cin is leaving the carriage return in the buffer
                getline(cin, address);

                modifyP->setAddress(address);

                cout << modifyP->getAddress() << " has been set to new address\n";
            }
            else if (choice == "P" || choice == "p")
            {
                cout << "Type a new phone number: " << endl;
                cin >> phone;

                modifyP->setPhone(phone);

                cout << modifyP->getPhone() << " has been set to new phone\n";
            }
            else if (choice == "E" || choice == "e")
            {
                cout << "Type a new email: " << endl;
                cin >> email;

                modifyP->setEmail(email);

                cout << modifyP->getEmail() << " has been set to new email\n";
            }
            else if (choice == "X" || choice == "x")
            {
                done = true;
            }
        }
    }
}
