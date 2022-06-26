#include <bits/stdc++.h>
#include "person.cpp"
#include "doc.cpp"
#include "pat.cpp"

using namespace std;

void patient_menu()
{
    char y;
    do
    {
        cout << "Choose a task" << endl;
        cout << "1. Add Patient's Information" << endl
             << "2. Delete Patient's Information" << endl
             << "3. Update Patient's Information" << endl
             << "4. Search Patient's Information" << endl
             << "5. Display Patient's Information" << endl
             << "6. Close" << endl;
        int i;
        cin >> i;
        system("cls");
        switch (i)
        {
        case 1:
            pat_add();
            break;
        case 2:
            delete_pat();
            break;
        case 3:
            update_pat();
            break;
        case 4:
            search_pat();
            break;
        case 5:
            show_pat();
            break;
        case 6:
            return;
            break;
        default:
            cout << "Invalid Operation" << endl;
            break;
        }
        cout << "Return to main menu (y/n)?" << endl;
        cin >> y;
        system("cls");
    } while (y == 'y' || y == 'Y');
    return;
}

void doctor_menu()
{
    char y;
    do
    {
        cout << "Choose a task" << endl;
        cout << "1. Add Doctor's Information" << endl
             << "2. Delete Doctor's Information" << endl
             << "3. Update Doctor's Information" << endl
             << "4. Search Doctor's Information" << endl
             << "5. Display Doctor's Information" << endl
             << "6. Close" << endl;
        int i;
        cin >> i;
        system("cls");
        switch (i)
        {
        case 1:
            doc_add();
            break;
        case 2:
            delete_doctor();
            break;
        case 3:
            update_doctor();
            break;
        case 4:
            search_doctor();
            break;
        case 5:
            show_doctor();
            break;
        case 6:
            return;
            break;
        default:
            cout << "Invalid Operation" << endl;
            break;
        }
        cout << "Return to main menu (y/n)?" << endl;
        cin >> y;
        system("cls");
    } while (y == 'y' || y == 'Y');
    return;
}

int main()
{
    // remove("patient.dat");
    char y;
    do
    {
        cout << "********** WELCOME TO HOSPITAL MANAGEMENT SYSTEM **********" << endl;
        cout << "1. Doctor's Directory" << endl
             << "2. Patient's Directory" << endl
             << "3. Close" << endl;
        int i;
        cin >> i;
        switch (i)
        {
        case 1:
            system("cls");
            doctor_menu();
            break;
        case 2:
            system("cls");
            patient_menu();
            break;
        case 3:
            system("cls");
            return 0;
        default:
            system("cls");
            cout << "Invalid Operation" << endl;
            break;
        }
        cout << "Return to main menu (y/n)?" << endl;
        cin >> y;
        system("cls");
    } while (y == 'y' || y == 'Y');
}