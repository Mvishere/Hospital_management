#include <iostream>
#include <string>
using namespace std;

class Appointment
{
private:
    int appointmentId;
    int doctorId;
    int patientId;
    string date;
    string time;

public:
    Appointment(int apptId, int docId, int patId, string date, string time)
        : appointmentId(apptId), doctorId(docId), patientId(patId), date(date), time(time) {}

    void reschedule(string newDate, string newTime)
    {
        date = newDate;
        time = newTime;
        cout << "Appointment rescheduled to " << date << " at " << time << endl;
    }

    void getDetails() const
    {
        cout << "Appointment ID: " << appointmentId << ", Doctor ID: " << doctorId
             << ", Patient ID: " << patientId << ", Date: " << date << ", Time: " << time << endl;
    }
};
