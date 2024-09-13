#include <iostream>
using namespace std;

int main() {
    // Enum representing employee types
    enum etype { laborer, secretary, manager, accountant, executive, researcher };
    
    char letter;  // Variable to store user input for first letter
    etype employee;  // Variable to store the enum value
    
    // Prompt the user to enter the first letter of employee type
    cout << "Enter employee type (first letter only)\n";
    cout << "(laborer, secretary, manager, accountant, executive, researcher): ";
    cin >> letter;
    
    // Use a switch statement to determine the input
    switch (letter) {
        case 'l': employee = laborer; break;
        case 's': employee = secretary; break;
        case 'm': employee = manager; break;
        case 'a': employee = accountant; break;
        case 'e': employee = executive; break;
        case 'r': employee = researcher; break;
        default: cout << "Invalid input.\n"; return 1;
    }
    
    // Use another switch statement to output the corresponding employee type
    cout << "Employee type is ";
    switch (employee) {
        case laborer: cout << "laborer."; break;
        case secretary: cout << "secretary."; break;
        case manager: cout << "manager."; break;
        case accountant: cout << "accountant."; break;
        case executive: cout << "executive."; break;
        case researcher: cout << "researcher."; break;
    }
    cout << endl;

    return 0;
}
