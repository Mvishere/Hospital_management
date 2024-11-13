#include <iostream>
#include <chrono>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Billing
{
private:
    int patientId;
    float totalAmount;
    float insuranceCoverage;
    string admit;

    chrono::system_clock::time_point parseDate(const string &date)
    {
        istringstream ss(date);
        tm tm = {};
        ss >> get_time(&tm, "%Y-%m-%d");

        if (ss.fail())
        {
            throw invalid_argument("Invalid date format. Please use YYYY-MM-DD.");
        }

        return chrono::system_clock::from_time_t(mktime(&tm));
    }

    int get_no_of_days(const string &inputDate)
    {
        try
        {
            auto admitDate = parseDate(inputDate);
            auto today = chrono::system_clock::now();

            auto duration = chrono::duration_cast<chrono::hours>(today - admitDate).count() / 24;
            return static_cast<int>(duration);
        }
        catch (const invalid_argument &e)
        {
            cerr << e.what() << endl;
        }

        return 0;
    }

public:
    Billing(int patientId, float dailyRate, float insuranceCoverage, string admit)
        : patientId(patientId), totalAmount(dailyRate), insuranceCoverage(insuranceCoverage), admit(admit) {}

    float calculatePayableAmount() const
    {
        int daysStayed = const_cast<Billing *>(this)->get_no_of_days(admit);
        float totalBill = totalAmount * daysStayed;
        return totalBill * (1 - insuranceCoverage);
    }

    void printBill() const
    {
        int daysStayed = const_cast<Billing *>(this)->get_no_of_days(admit);

        cout << "Patient ID: " << patientId << endl;
        cout << "Days Stayed: " << daysStayed << " days" << endl;
        cout << "Daily Rate: ₹" << totalAmount << endl;
        cout << "Total Amount (without insurance): ₹" << totalAmount * daysStayed << endl;
        cout << "Insurance Coverage: " << insuranceCoverage * 100 << "%" << endl;
        cout << "Amount Payable (after insurance): ₹" << calculatePayableAmount() << endl;
    }
};