#include <bits/stdc++.h>
#include "person.cpp"

using namespace std;

static bool comp(const patient &a, const patient &b)
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

void pat_add()
{
    patient a;
    a.fill();
    ofstream f("patient.dat", ios::binary | ios::out);
    f.write((char *)&a, sizeof(a));
    f.close();
    cout << "Patient's Information Added Successfully!" << endl;
}

void delete_pat()
{
    cout << "Enter ID No: ";
    int pat_id;
    cin >> pat_id;
    patient a;
    ifstream f("patient.dat", ios::binary | ios::in);
    ofstream t("temp.dat", ios::binary | ios::out);
    while (f.read((char *)&a, sizeof(a)))
    {
        if (a.get_id() == pat_id)
        {
            continue;
        }
        t.write((char *)&a, sizeof(a));
    }
    f.close();
    t.close();
    remove("patient.dat");
    rename("temp.dat", "patient.dat");
    cout << "Patients's Details Deleted Successfully!" << endl;
}

void update_pat()
{
    cout << "Enter ID No: ";
    int pat_id;
    cin >> pat_id;
    patient a;
    ifstream f("patient.dat", ios::binary | ios::in);
    ofstream t("temp.dat", ios::binary | ios::out);
    while (f.read((char *)&a, sizeof(a)))
    {
        if (a.get_id() == pat_id)
        {
            a.update();
        }
        t.write((char *)&a, sizeof(a));
    }
    f.close();
    t.close();
    remove("patient.dat");
    rename("temp.dat", "patient.dat");
    cout << "Patients's Details Updated Successfully!" << endl;
}

void search_pat()
{
    cout << "Enter ID No: ";
    int pat_id;
    cin >> pat_id;
    patient a;
    bool flag = false;
    ifstream f("patient.dat", ios::binary | ios::in);
    while (f.read((char *)&a, sizeof(a)))
    {
        if (a.get_id() == pat_id)
        {
            flag = true;
            a.display();
        }
    }
    f.close();
    if (!flag)
    {
        cout << "No Patient Found!" << endl;
    }
}

void show_pat()
{
    patient a;
    ifstream f("patient.dat", ios::binary | ios::in);
    while (f.read((char *)&a, sizeof(a)))
    {
        a.display();
    }
    f.close();
}
