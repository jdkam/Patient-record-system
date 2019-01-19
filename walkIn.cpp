//client code

#include "Patient.cpp"
#include <iostream>
#include <string>

using namespace std;

int main(){
char choice;

cout << "[E] Enter a new Patient:" << endl
<< "[R] Remove an existing Patient" << endl
<< "[S] Search for an existing Patient" << endl
<< "[M] Modify an existing Patient" << endl
<< "[P] Print list of all Patients" << endl;

cin >> choice;

if (choice == 'E' || choice == 'e'){
    newPatient();
}

//cout << "Enter name: " << endl;
//getline(cin, name);
//p.setName(name);

//cout << p.getName() << endl;

cout << "       ************FINISHED EXECUTABLE************ " << endl;

}

void newPatient() {
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
    getline(cin,name);
    p.setName(name); //set patients name to entered name
    cout << "Patient's name set to: " << p.getName() << "\n\n";

//grab address
    cout << "Enter Patient's address: " ;
    getline(cin, address);
    p.setAddress(address);
    cout << "Address set to: " << p.getAddress() << "\n\n";
   
//grab phone
    cout << "Enter Patient's phone number: ";
    getline(cin, phone);
    p.setPhone(phone);
    cout << "Phone number set to: " << p.getPhone() << "\n\n";

//grab email
    cout << "Enter Patient's email: ";
    getline(cin, email);
    p.setEmail(email);
    cout << "Email set to: " << p.getEmail() << "\n\n";

}