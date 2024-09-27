#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string EmpName;
    int ID;
    float BaseSalary;
    int JoiningYear;
    static int currentYear;

public:
    Employee() {
        currentYear = 2024;
    }

    void FeedInfo() {
        cout << "Enter Employee Name: ";
        cin >> EmpName;
        cout << "Enter Employee ID: ";
        cin >> ID;
        cout << "Enter Base Salary: ";
        cin >> BaseSalary;
        cout << "Enter Joining Year: ";
        cin >> JoiningYear;
    }

    float calculateTotalSalary() {
        int yearsOfService = currentYear - JoiningYear;
        float updatedBaseSalary = BaseSalary;

        for (int i = 0; i < yearsOfService; ++i) {
            updatedBaseSalary *= 1.03;
        }

        float totalSalary = updatedBaseSalary + (updatedBaseSalary * 0.10) + (updatedBaseSalary * 0.30) + (updatedBaseSalary * 0.10);

        return totalSalary;
    }

    string getStatus(int age, float totalSalary, string &status) {
        if (age <= 25) {
            if (totalSalary <= 20000) status = "Low";
            else if (totalSalary > 20000) status = "Moderate";
        } else if (age > 25) {
            if (totalSalary <= 21000) status = "Low";
            else if (totalSalary > 21000 && totalSalary <= 60000) status = "Moderate";
            else if (totalSalary > 60000) status = "High";
        }
        return status;
    }

    float calculateBonus(string status, float totalSalary) {
        if (status == "Low") return totalSalary * 0.05;
        else if (status == "Moderate") return totalSalary * 0.10;
        else if (status == "High") return totalSalary * 0.15;
        return 0;
    }

    void ShowInfo() {
        int age;
        cout << "Enter Employee Age: ";
        cin >> age;

        float totalSalary = calculateTotalSalary();
        string status;
        getStatus(age, totalSalary, status);
        float bonus = calculateBonus(status, totalSalary);

        cout << "\nEmployee Details:" << endl;
        cout << "Name: " << EmpName << endl;
        cout << "ID: " << ID << endl;
        cout << "Base Salary: " << BaseSalary << endl;
        cout << "Total Salary: " << totalSalary << endl;
        cout << "Status: " << status << endl;
        cout << "Bonus: " << bonus << endl;
    }
};

int Employee::currentYear = 2024;

int main() {
    Employee emp;
    emp.FeedInfo();
    emp.ShowInfo();
    return 0;
}
