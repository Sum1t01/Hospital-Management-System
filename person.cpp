#ifndef PERSON_H
#define PERSON_H

#include <bits/stdc++.h>

using namespace std;

class person
{

    double age;
    char contact[20];

public:
    char first_name[30], last_name[30];
    void fill()
    {
        cout << "Enter First Name: ";
        cin >> first_name;
        cout << "Enter Last Name: ";
        cin >> last_name;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Contact Number: ";
        cin >> contact;
    }

    void display()
    {
        cout << "Name:      " << first_name << " " << last_name << endl
             << "Age:       " << age << endl
             << "Number:    " << contact << endl;
    }

    void update()
    {
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Contact Number: ";
        cin >> contact;
    }
};

class doctor : public person
{
    int id_no;
    char department[30];

public:
    void fill()
    {
        person::fill();
        cout << "Enter ID No. ";
        cin >> id_no;
        cout << "Enter Department. ";
        cin >> department;
    }

    void display()
    {
        person::display();
        cout << "ID No.      " << id_no << endl;
        cout << "Department: " << id_no << endl;
    }

    int get_id()
    {
        return id_no;
    }
};

class patient : public person
{
    int patient_id;
    int doc_assigned;

public:
    void fill()
    {
        person::fill();
        cout << "Enter ID No. ";
        cin >> patient_id;
        cout << "Enter assigned Doctor's ID: ";
        cin >> doc_assigned;
    }

    void display()
    {
        person::display();
        cout << "ID No.           " << patient_id << endl
             << "Doctor Assigned: " << doc_assigned << endl;
    }

    int get_id()
    {
        return patient_id;
    }
};

#endif