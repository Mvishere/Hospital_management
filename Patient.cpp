#include <iostream>
#include "Person.cpp"
using namespace std;

class Patient : public Person
{
private:
    int id;
    string diseaseType;
    string discharge;
    string admitted;
    int doctorId;

public:
    Patient(int id, string name, int age, string email, long long phoneNumber, string address, char gender, string diseaseType, string admitted) : Person(name, age, email, phoneNumber, address, gender)
    {
        this->id = id;
        this->admitted = admitted;
        this->diseaseType = diseaseType;
        this->doctorId = doctorId;
    }

    void updateDischargeDate(string discharge)
    {
        this->discharge = discharge;
        cout << "Updated to " << discharge << endl;
    }
    int getId()
    {
        return this->id;
    }
};