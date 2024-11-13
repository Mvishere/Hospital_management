#include <iostream>
#include "Person.cpp"
#include "./utils/Bill.cpp"
#include <iomanip>

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

    void const get_detail()
    {
        cout << setw(4) << id;
        Person ::get_detail();
        cout << setw(15) << diseaseType;
        cout << endl;
    }

    void setDoctorId(int doctorId)
    {
        this->doctorId = doctorId;
    }

    string getDiseaseType()
    {
        return this->diseaseType;
    }

    void generate_bill()
    {
        Billing b(this->id, 1000, 0.1, this->admitted);
        b.printBill();
    }
};