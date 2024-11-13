#include <iostream>
#pragma once
#include "Staff.cpp"
using namespace std;

class Nurse : public Staff
{
protected:
    string department;
    string designation;

public:
    Nurse(string name, int age, string email, long long phoneNumber, string address, char gender, int employeeId, string joiningDate, int salary, string department, string designation) : Staff(name, age, email, phoneNumber, address, gender, employeeId, joiningDate, salary)
    {

        this->department = department;
        this->designation = designation;
    }
    void updateDesignation(string newDesignation)
    {

        cout << "Nurse's designation updated to: " << newDesignation << endl;
        this->designation = newDesignation;
    }
};
