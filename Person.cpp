#include <iostream>
#include <iomanip>
#pragma once
using namespace std;

class Person
{
protected:
    string name;
    int age;
    string email;
    long long phoneNumber;
    string address;
    char gender;

public:
    Person(string name, int age, string email, long long phoneNumber, string address, char gender)
    {
        this->name = name;
        this->age = age;
        this->email = email;
        this->phoneNumber = phoneNumber;
        this->address = address;
        this->gender = gender;
    }

    void const get_detail() // updated
    {
        cout << setw(10) << this->name;
        cout << setw(5) << this->age;
        cout << setw(25) << this->email;
        cout << setw(14) << this->phoneNumber;
        cout << setw(15) << this->address;
        cout << setw(10) << this->gender;
    }

    void update_detail(string detail, int value)
    {
        if (detail == "age")
        {
            age = value;
            cout << "Updated " << detail << " to " << value << endl;
        }
        else
        {
            cout << "Error: Invalid input" << endl;
        }
    }

    void update_detail(string detail, long long value)
    {
        if (detail == "phone")
        {
            phoneNumber = value;
            cout << "Updated " << detail << " to " << value << endl;
        }
        else
        {
            cout << "Error: Invalid input" << endl;
            cout << "Updated " << detail << " to " << value << endl;
        }
    }

    void update_detail(string detail, string value)
    {
        if (detail == "name")
        {
            name = value;
            cout << "Updated " << detail << " to " << value << endl;
        }
        else if (detail == "email")
        {
            email = value;
            cout << "Updated " << detail << " to " << value << endl;
        }
        else if (detail == "address")
        {
            address = value;
            cout << "Updated " << detail << " to " << value << endl;
        }
        else
        {
            cout << "Error: Invalid input" << endl;
        }
    }

    void update_detail(string detail, char value)
    {
        if (detail == "gender")
        {
            this->gender = value;
            cout << "Updated " << detail << " to " << value << endl;
        }
        else
        {
            cout << "Error: Invalid input" << endl;
        }
    }
};