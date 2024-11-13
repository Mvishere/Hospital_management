#include <iostream>
#pragma once
#include "Person.cpp"

using namespace std;

class Staff : public Person
{

protected:
    int employeeId;
    string joiningDate;
    int salary;

public:
    Staff(string name, int age, string email, long long phoneNumber, string address, char gender, int employeeId, string joiningDate, int salary) : Person(name, age, email, phoneNumber, address, gender)
    {
        this->employeeId = employeeId;
        this->joiningDate = joiningDate;
        this->salary = salary;
    }

    void update_salary(int new_salary)
    {
        salary = new_salary;
        cout << "Updated Salary to" << new_salary << endl;
    }

    int get_id()
    {
        return employeeId;
    }
};