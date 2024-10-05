// Employee.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

// Employee Class
class Employee {
private:
    string name;
    string dateOfBirth;
    float baseSalary;
    int joiningYear;

public:
    // Constructor
    Employee(string n = "John Doe", string dob = "01-01-2002", float salary = 10000, int year = 2000)
        : name(n), dateOfBirth(dob), baseSalary(salary), joiningYear(year) {
        if (name.length() <= 2) name = "John Doe";
        if (calculateAge() < 18) dateOfBirth = "01-01-2002";
        if (baseSalary < 10000 || baseSalary > 100000) baseSalary = 10000;
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Getter and Setter Methods
    string getName() const { return name; }
    void setName(string n) {
        if (n.length() > 2) name = n;
        else name = "John Doe";
    }

    string getDateOfBirth() const { return dateOfBirth; }
    void setDateOfBirth(string dob) {
        dateOfBirth = dob;
        if (calculateAge() < 18) dateOfBirth = "01-01-2002";
    }

    float getBaseSalary() const { return baseSalary; }
    void setBaseSalary(float salary) {
        if (salary >= 10000 && salary <= 100000)
            baseSalary = salary;
        else
            baseSalary = 10000;
    }

    int getJoiningYear() const { return joiningYear; }
    void setJoiningYear(int year) { joiningYear = year; }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Function to calculate age based on the date of birth
    int calculateAge() const {
        int currentYear = 2024;
        int birthYear = stoi(dateOfBirth.substr(6, 4));
        return currentYear - birthYear;
    }


    float calculateTotalSalary() const {
        float updatedSalary = baseSalary;
        int yearsOfService = 2024 - joiningYear; // Assuming current year is 2024
        updatedSalary += (yearsOfService * 0.03) * baseSalary; // 3% per year increase
        return updatedSalary + updatedSalary * 0.10 + updatedSalary * 0.30 + updatedSalary * 0.10;
    }

    float calculateBonus() const {
        string status = getStatus();
        float totalSalary = calculateTotalSalary();
        if (status == "Low") return totalSalary * 0.05;
        else if (status == "Moderate") return totalSalary * 0.10;
        else return totalSalary * 0.15;
    }

    // Function to get employee status
    string getStatus() const {
        float totalSalary = calculateTotalSalary();
        int age = calculateAge();

        if (age <= 25 && totalSalary <= 20000) return "Low";
        else if (age <= 25 && totalSalary > 20000) return "Moderate";
        else if (age > 25 && totalSalary <= 21000) return "Low";
        else if (age > 25 && totalSalary > 21000 && totalSalary <= 60000) return "Moderate";
        else return "High";
    }

    // Const member function to compare total salary with another employee
    const Employee& compareTotalSalary(const Employee& e) const {
        return this->calculateTotalSalary() > e.calculateTotalSalary() ? *this : e;
    }

    // Function to set all information using setter functions
    void setInfo() {
        string n, dob;
        float salary;
        int year;
        cout << "Enter Name: ";
        cin >> n;
        setName(n);
        cout << "Enter Date of Birth (DD-MM-YYYY): ";
        cin >> dob;
        setDateOfBirth(dob);
        cout << "Enter Base Salary: ";
        cin >> salary;
        setBaseSalary(salary);
        cout << "Enter Joining Year: ";
        cin >> year;
        setJoiningYear(year);
    }

    // Function to display employee information
    void getInfo() const {
        cout << "Name: " << name << endl;
        cout << "Date of Birth: " << dateOfBirth << endl;
        cout << "Base Salary: " << baseSalary << endl;
        cout << "Joining Year: " << joiningYear << endl;
        cout << "Total Salary: " << calculateTotalSalary() << endl;
        cout << "Status: " << getStatus() << endl;
        cout << "Bonus: " << calculateBonus() << endl;
    }
};

// Function to generate random information for an employee
void generateInformationRandom(Employee& e) {
    e.setName("Employee" + to_string(rand() % 100));
    e.setDateOfBirth("01-01-" + to_string(1980 + rand() % 40)); // Random birth year from 1980 to 2020
    e.setBaseSalary(10000 + rand() % 90001); // Random salary between 10000 and 100000
    e.setJoiningYear(1990 + rand() % 35); // Random joining year between 1990 and 2024
}

// Function to show all employees based on total salary in ascending order
void ShowAllBasedOnTotalSalary(Employee ar[], int size) {
    sort(ar, ar + size, [](const Employee& a, const Employee& b) {
        return a.calculateTotalSalary() < b.calculateTotalSalary();
        });

    for (int i = 0; i < size; i++) {
        cout << ar[i].getName() << " - Total Salary: " << ar[i].calculateTotalSalary() << endl;
    }
}

// int main() {
//     Employee employees[3];


//     for (int i = 0; i < 3; i++) {
//         generateInformationRandom(employees[i]);
//     }

//     // Show all employees sorted by total salary
//     ShowAllBasedOnTotalSalary(employees, 3);

//     return 0;
// }

int main() {
    // Create three employees using the constructor
    Employee emp1("Alice", "15-07-1998", 15000, 2015);
    Employee emp2("Bob", "10-11-1985", 20000, 2010);
    Employee emp3("Charlie", "20-05-1992", 18000, 2018);

    // Display information of each employee
    cout << "Initial Employee Information:\n";
    emp1.getInfo();
    cout << endl;
    emp2.getInfo();
    cout << endl;
    emp3.getInfo();
    cout << endl;

    // Set new information for emp1 using setInfo()
    cout << "Updating Employee 1 Information:\n";
    emp1.setInfo();
    emp1.getInfo();
    cout << endl;

    // Compare total salary of two employees
    cout << "Comparing total salary of Employee 1 and Employee 2:\n";
    Employee higherSalary = emp1.compareTotalSalary(emp2);
    cout << higherSalary.getName() << " has a higher total salary.\n\n";

    // Generate random information for employees
    cout << "Generating random information for three employees:\n";
    generateInformationRandom(emp1);
    generateInformationRandom(emp2);
    generateInformationRandom(emp3);

    // Display updated information
    emp1.getInfo();
    cout << endl;
    emp2.getInfo();
    cout << endl;
    emp3.getInfo();
    cout << endl;

    // Show all employees sorted by total salary
    cout << "Employees sorted by total salary:\n";
    Employee employees[] = { emp1, emp2, emp3 };
    ShowAllBasedOnTotalSalary(employees, 3);

    return 0;
}
