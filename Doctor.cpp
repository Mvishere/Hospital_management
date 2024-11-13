#include <iostream>
#include <iomanip>
#pragma once
#include "Staff.cpp"
using namespace std;

class Doctor : public Staff
{
protected:
    string department;
    string designation;

public:
    Doctor(string name, int age, string email, long long phoneNumber, string address, char gender, int employeeId, string joiningDate, int salary, string department, string designation) : Staff(name, age, email, phoneNumber, address, gender, employeeId, joiningDate, salary)
    {

        this->department = department;
        this->designation = designation;
    }
    void updateDesignation(string newDesignation)
    {

        cout << "Doctor's designation updated to: " << newDesignation << endl;
        this->designation = newDesignation;
    }

    void const get_detail()
    {
        Person ::get_detail();
        cout << setw(13) << this->employeeId;
        cout << setw(15) << this->joiningDate;
        cout << setw(10) << this->salary;
        cout << setw(18) << this->department;
        cout << setw(16) << this->designation;
    }
    void const d_get_detail()
    {
        cout << setw(13) << this->employeeId;
        cout << setw(15) << this->joiningDate;
        cout << setw(10) << this->salary;
        cout << setw(18) << this->department;
        cout << setw(16) << this->designation;
    }
};