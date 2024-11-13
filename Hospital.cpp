#include <iostream>
#include <bits/stdc++.h>
#include "Person.cpp"
#include "Patient.cpp"
#include "Nurse.cpp"
#include "Doctor.cpp"
#include <chrono>
#include <ctime>
#include "./utils/Appointment.cpp"
using namespace std;
class Hospital
{
private:
    const int totalBeds = 5;

protected:
    string name;
    string address;
    vector<Doctor> doctors;
    vector<Patient> patient;
    vector<Nurse> nurses;
    int beds = 0;

public:
    Hospital(string name, string address, vector<Doctor> doctors, vector<Nurse> nurses, vector<Patient> patient)
    {
        this->address = address;
        this->name = name;
        this->patient = patient;
        this->doctors = doctors;
        this->nurses = nurses;
    }

    void admitPatient(Patient newPatient)
    {
        if (beds == totalBeds)
        {
            cout << "No Beds available sorry : (" << endl;
            return;
        }
        int n = this->patient.size();
        for (int i = 0; i < n; i++)
        {
            auto temp = this->patient[i];
            if (temp.getId() == newPatient.getId())
            {
                cout << "Patient is already admitted!" << endl;
                return;
            }
        }
        this->patient.push_back(newPatient);
        this->beds = this->beds + 1;
        int dn = this->doctors.size();

        for (int j = 0; j < dn; j++)
        {
            auto &temp = this->doctors[j];
            if (temp.getDepartment() == newPatient.getDiseaseType())
            {
                newPatient.setDoctorId(temp.get_id());
                temp.addPatient(newPatient);
                cout << "Patient admitted successfully" << endl;
            }
        }
    }
    void printArray(auto temp)
    {
        for (auto &element : temp)
        {
            element.get_detail();
        }
    }

    int getNoBeds()
    {
        return this->beds;
    }
    void getDetails()
    {
        cout << "Hospital name: " << this->name << endl;
        cout << "Address: " << this->address << endl;
        cout << "No of rooms/beds available: " << totalBeds - this->beds << endl;
        cout << "No of Doctors/Nurse employed: " << this->doctors.size() << "/" << this->nurses.size() << endl;
        cout << "No of patients admitted: " << this->patient.size() << endl;
        cout << "No of total Capacity: " << this->totalBeds << endl;
    }

    void updateDetails(string type, string detail)
    {
        if (type == "name")
        {
            this->name = name;
            cout << "Hospital name updated successfully." << endl;
        }
        else if (type == "address")
        {
            this->address = address;
            cout << "Hospital address updated successfully." << endl;
        }
        else
        {
            cout << "Invalid Updation! Please try again." << endl;
        }
    }

    void dischargePatient(int patientId)
    {
        int n = this->patient.size();
        for (int i = 0; i < n; i++)
        {
            auto temp = this->patient[i];
            if (temp.getId() == patientId)
            {
                auto now = chrono::system_clock::now();
                time_t currentTime = chrono::system_clock::to_time_t(now);

                temp.updateDischargeDate(ctime(&currentTime));
                this->patient.erase(this->patient.begin() + i);
                patient[i].generate_bill();

                this->beds = this->beds - 1;

                int dn = this->doctors.size();

                for (int k = 0; k < dn; k++)
                {
                    auto tempD = this->doctors[k];
                    auto patientD = tempD.getPatient();
                    if (tempD.getDepartment() == temp.getDiseaseType())
                    {
                        for (int j = 0; j < patientD.size(); j++)
                        {
                            if (patientD[j].getId() == patientId)
                            {
                                patientD.erase(patientD.begin() + j);
                                cout << "Patient discharge successfully! Stay healthy." << endl;
                                return;
                            }
                        }
                    }
                }
                return;
            }
        }
        cout << "Patient not found!" << endl;
    }

    void hireDoctor(Doctor doctor)
    {
        int n = this->doctors.size();
        for (int i = 0; i < n; i++)
        {
            auto temp = this->doctors[i];
            if (temp.get_id() == doctor.get_id())
            {
                cout << "Doctor is already there!" << endl;
                return;
            }
        }
        this->doctors.push_back(doctor);
        cout << "Doctor added successfully" << endl;
    }

    void hireNurse(Nurse nurse)
    {
        int n = this->nurses.size();
        for (int i = 0; i < n; i++)
        {
            auto temp = this->nurses[i];
            if (temp.get_id() == nurse.get_id())
            {
                cout << "Nurse is already there!" << endl;
                return;
            }
        }
        this->nurses.push_back(nurse);
        cout << "Nurse hired successfully" << endl;
    }
    void fireStaff(Nurse nurse)
    {
        int n = this->nurses.size();
        for (int i = 0; i < n; i++)
        {
            auto temp = this->nurses[i];
            if (temp.get_id() == nurse.get_id())
            {
                this->nurses.erase(this->nurses.begin() + i);
                cout << "Nurse fired successfully! Stay healthy." << endl;
                return;
            }
        }
        cout << "Nurse not found!" << endl;
    }
    void fireStaff(Doctor doctor)
    {
        int n = this->doctors.size();
        for (int i = 0; i < n; i++)
        {
            auto temp = this->doctors[i];
            if (temp.get_id() == doctor.get_id())
            {
                this->doctors.erase(this->doctors.begin() + i); // nurses->doctors
                cout << "Doctor fired successfully! Stay healthy." << endl;
                return;
            }
        }
        cout << "Doctor not found!" << endl;
    }
    void printPatient()
    {
        int n = patient.size();
        cout << setw(4) << "id";
        cout << setw(10) << "Name";
        cout << setw(5) << "age";
        cout << setw(25) << "email";
        cout << setw(14) << "phoneNumber";
        cout << setw(15) << "address";
        cout << setw(10) << "gender";
        cout << setw(15) << "disease type";
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            patient[i].get_detail();
            cout << endl;
        }
    }
    void printDoctors()
    {
        int n = doctors.size();
        cout << endl
             << "->This is Doctor Staff : " << endl; // add nurses

        cout << left << setw(13) << "employeeId";
        cout << left << setw(15) << "joiningDate";
        cout << left << setw(10) << "salary";
        cout << left << setw(18) << "department";
        cout << left << setw(16) << "designation";
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            doctors[i].d_get_detail();
            cout << endl;
        }
    }
    void printNurses()
    {
        int n = nurses.size();
        cout << endl
             << "--> This is Nurses Staff : " << endl
             << endl; // add nurses

        cout << setw(10) << "Name";
        cout << setw(5) << "age";
        cout << setw(25) << "email";
        cout << setw(14) << "phoneNumber";
        cout << setw(15) << "address";
        cout << setw(10) << "gender";
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            nurses[i].get_detail();
            cout << endl;
        }
    }
};

int main()
{
    vector<Doctor> doctors;
    vector<Nurse> nurses;
    vector<Patient> patients;
    Hospital H("Manan", "ews", doctors, nurses, patients);
    int patient_count = 2;
    int doctor_count = 3;
    Doctor M("Manas", 19, "isheremv@gmail.com", 8212412412, "ews", 'm', 1, "2024-11-11", 1000000, "orthopedics", "junior doctor");
    Doctor M2("Manas", 19, "isheremv@gmail.com", 8212412412, "ews", 'm', 2, "2024-11-11", 1000000, "heart", "junior doctor");
    H.hireDoctor(M);
    H.hireDoctor(M2);
    H.printDoctors();
    Patient p(1, "pratham", 19, "awda@gmail.com", 1234567891, "ews", 'm', "orthopedics", "2024-11-11");
    H.admitPatient(p);
    H.dischargePatient(1);
    // Patient p(, "pratham", 19, "awda@gmail.com", 1234567891, "ews", 'm', "orthopedics", "11/12/2024");

    int choice;
    while (true)
    {
        cout << "\n===== Hospital Management System =====" << endl;
        cout << "1. Patient Management" << endl;
        cout << "2. Doctor Management" << endl;
        cout << "3. Nurse Management" << endl;
        cout << "4. Hospital Information" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0)
        {
            cout << endl
                 << "Welcome for visiting, Thank You!" << endl;
            break;
        }

        switch (choice)
        {
        case 1:
        {
            int patientChoice;
            cout << "\n--- Patient Management ---" << endl;
            cout << "1. Admit New Patient" << endl;
            cout << "2. Discharge Patient" << endl;
            cout << "3. View All Patients" << endl;
            cout << "Enter your choice: ";
            cin >> patientChoice;

            switch (patientChoice)
            {
            case 1:
            {
                int id, age;
                string name, email, address, disease, admissionDate;
                long phone;
                char gender;
                id = patient_count;
                patient_count++;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Age: ";
                cin >> age;
                cout << "Enter Email: ";
                cin >> email;
                cout << "Enter Phone: ";
                cin >> phone;
                cout << "Enter Address: ";
                cin >> address;
                cout << "Enter Gender (M/F): ";
                cin >> gender;
                cout << "Enter Disease: ";
                cin >> disease;
                cout << "Enter Admission Date (DD/MM/YYYY): ";
                cin >> admissionDate;

                Patient newPatient(id, name, age, email, phone, address, gender, disease, admissionDate);
                H.admitPatient(newPatient);
                break;
            }
            case 2:
            {
                int patientId;
                cout << "Enter Patient ID to discharge: ";
                cin >> patientId;
                H.dischargePatient(patientId);
                break;
            }
            case 3:
                H.printPatient();
                break;
            default:
                cout << "Invalid choice! Returning to main menu." << endl;
            }
            break;
        }
        case 2:
        {
            int doctorChoice;
            cout << "\n--- Doctor Management ---" << endl;
            cout << "1. Hire New Doctor" << endl;
            cout << "2. Fire Doctor" << endl;
            cout << "3. View All Doctors" << endl;
            cout << "Enter your choice: ";
            cin >> doctorChoice;

            switch (doctorChoice)
            {
            case 1:
            {
                int id, age, salary;
                string name, email, address, department, designation, joiningDate;
                long long phone;
                char gender;

                id = doctor_count;
                doctor_count++;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Age: ";
                cin >> age;
                cout << "Enter Email: ";
                cin >> email;
                cout << "Enter Phone: ";
                cin >> phone;
                cout << "Enter Address: ";
                cin >> address;
                cout << "Enter Gender (M/F): ";
                cin >> gender;
                cout << "Enter Joining Date : ";
                cin >> joiningDate;
                cout << "Enter Salary: ";
                cin >> salary;
                cout << "Enter Department: ";
                cin >> department;
                cout << "Enter Designation: ";
                cin >> designation;

                Doctor newDoctor(name, age, email, phone, address, gender, id, joiningDate, salary, department, designation);
                H.hireDoctor(newDoctor);
                break;
            }
            case 2:
            {
                int doctorId;
                cout << "Enter Doctor ID to fire: ";
                cin >> doctorId;
                Doctor tempDoctor("", 0, "", 0, "", 'M', doctorId, "", 10000, "", "");
                H.fireStaff(tempDoctor);
                break;
            }
            case 3:
                H.printDoctors();
                break;
            default:
                cout << "Invalid choice! Returning to main menu." << endl;
            }
            break;
        }
        case 3:
        {
            int nurseChoice;
            cout << "\n--- Nurse Management ---" << endl;
            cout << "1. Hire New Nurse" << endl;
            cout << "2. Fire Nurse" << endl;
            cout << "3. View All Nurses" << endl;
            cout << "Enter your choice: ";
            cin >> nurseChoice;

            switch (nurseChoice)
            {
            case 1:
            {
                int id, age;
                string name, email, address, department, joiningDate, designation;
                long phone;
                char gender;
                double salary;

                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Age: ";
                cin >> age;
                cout << "Enter Email: ";
                cin >> email;
                cout << "Enter Phone: ";
                cin >> phone;
                cout << "Enter Address: ";
                cin >> address;
                cout << "Enter Gender (M/F): ";
                cin >> gender;
                cout << "Enter Nurse ID: ";
                cin >> id;
                cout << "Enter Joining Date : ";
                cin >> joiningDate;
                cout << "Enter Salary: ";
                cin >> salary;
                cout << "Enter Department: ";
                cin >> department;
                cout << "Enter Designation : ";
                cin >> designation;

                Nurse newNurse(name, age, email, phone, address, gender, id, joiningDate, salary, department, designation);
                H.hireNurse(newNurse);
                break;
            }
            case 2:
            {
                int nurseId;
                cout << "Enter Nurse ID to fire: ";
                cin >> nurseId;
                Nurse tempNurse("", 0, "", 0, "", 'M', nurseId, "", 10000, "", "");
                H.fireStaff(tempNurse);
                break;
            }
            case 3:
            {
                H.printNurses();
                break;
            }
            default:
                cout << "Invalid choice! Returning to main menu." << endl;
            }
            break;
        }
        case 4:
            H.getDetails();
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}