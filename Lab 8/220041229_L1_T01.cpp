#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;

public:
    Person(string n) : name(n) {}
    virtual void display() { cout << "Name: " << name << endl; }
};



class Employee : public Person {
private:
    int employeeID;
protected:
    float salary;
    

public:
    Employee(string n, int id, float s) : Person(n), employeeID(id), salary(s) {}
    void display()  { cout << "Name: " << name << ", ID: " << employeeID << ", Salary: " << salary << endl; }
    int getEmployeeID() { return employeeID; }
};



class Intern : public Employee {
private:
    string schoolName;

public:
    Intern(string n, int id, float s, string school) : Employee(n, id, s), schoolName(school) {}
    void display()  { cout << "Name: " << name << ", ID: " << getEmployeeID() << ", Salary: " << salary << ", School: " << schoolName << endl; }
};



class Manager : public Employee {
private:
    string department;

public:
    Manager(string n, int id, float s, string dept) : Employee(n, id, s), department(dept) {}
    string get_department(){return department;}
    void display()  { cout << "Name: " << name << ", ID: " << getEmployeeID() << ", Salary: " << salary << ", Department: " << department << endl; }
};



class Director : public Manager {
private:
    float bonus;

public:
    Director(string n, int id, float s, string dept, float b) : Manager(n, id, s, dept), bonus(b) {}
    void display()  { cout << "Name: " << name << ", ID: " << getEmployeeID() << ", Salary: " << salary << ", Department: " << get_department() << ", Bonus: " << bonus << endl; }
};





int main() {
    Intern intern("John", 1001, 3000, "XYZ University");
    Manager manager("Alice", 1002, 8000, "Sales");
    Director director("Bob", 1003, 15000, "Marketing", 2000);

    intern.display();
    manager.display();
    director.display();
    return 0;
}