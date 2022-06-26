#include <bits/stdc++.h>
#include "person.cpp"

using namespace std;

static bool comp(const doctor &a, const doctor &b)
{
    if (strcmp(a.first_name, b.last_name) == 0)
    {
        if (strcmp(a.last_name, b.last_name) < 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (strcmp(a.first_name, b.first_name) < 0)
    {
        return true;
    }
    return false;
}

void doc_add()
{
    doctor a;
    a.fill();
    ofstream f("doctor.dat", ios::binary | ios::out);
    f.write((char *)&a, sizeof(a));
    f.close();
    cout << "Doctor's Information Added Successfully!" << endl;
}

void delete_doctor()
{
    cout << "Enter ID No: ";
    int doc_id;
    cin >> doc_id;
    doctor a;
    ifstream f("doctor.dat", ios::binary | ios::in);
    ofstream t("temp.dat", ios::binary | ios::out);
    while (f.read((char *)&a, sizeof(a)))
    {
        if (a.get_id() == doc_id)
        {
            continue;
        }
        t.write((char *)&a, sizeof(a));
    }
    f.close();
    t.close();
    remove("doctor.dat");
    rename("temp.dat", "doctor.dat");
    cout << "Doctor's Details Deleted Successfully!" << endl;
}

void update_doctor()
{
    cout << "Enter ID No: ";
    int doc_id;
    cin >> doc_id;
    doctor a;
    ifstream f("doctor.dat", ios::binary | ios::in);
    ofstream t("temp.dat", ios::binary | ios::out);
    while (f.read((char *)&a, sizeof(a)))
    {
        if (a.get_id() == doc_id)
        {
            a.update();
        }
        t.write((char *)&a, sizeof(a));
    }
    f.close();
    t.close();
    remove("doctor.dat");
    rename("temp.dat", "doctor.dat");
    cout << "Doctor's Details Updated Successfully!" << endl;
}

void search_doctor()
{
    cout << "Enter ID No: ";
    int doc_id;
    cin >> doc_id;
    doctor a;
    bool flag = false;
    ifstream f("doctor.dat", ios::binary | ios::in);
    while (f.read((char *)&a, sizeof(a)))
    {
        if (a.get_id() == doc_id)
        {
            flag = true;
            a.display();
        }
    }
    f.close();
    if (!flag)
    {
        cout << "No Doctor Found!" << endl;
    }
}

void show_doctor()
{
    doctor a;
    ifstream f("doctor.dat", ios::binary | ios::in);
    while (f.read((char *)&a, sizeof(a)))
    {
        a.display();
    }
    f.close();
}