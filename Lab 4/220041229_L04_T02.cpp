#include <bits/stdc++.h>
using namespace std;

class BankAccount {
    private:
        static int totalAccounts;
        static int totalAccountPresent;
        static double totalTaxCollected;

        float account_number;
        string holder_name;
        string account_type;
        float balance;
        const float min_balance;

    public:
        BankAccount(float account_number, string holder_name, float balance, float min_balance)
            : account_number(account_number), holder_name(holder_name), account_type("N/A"), balance(balance), min_balance(min_balance) {
            totalAccounts++;
            totalAccountPresent++;
        }

        ~BankAccount() {
            cout << "Account of Mr./Ms. " << holder_name << " with account no " 
                 << account_number << " is destroyed with a balance of BDT " << balance << endl;
            totalAccountPresent--;
        }

        void accountType(string type) {
            if (type == "Current" || type == "Savings") {
                account_type = type;
            } else {
                cout << "Invalid account type" << endl;
            }
        }

        void showBalance() {
            cout << "Balance: " << balance << endl;
        }

        void deposit(float amount) {
            if (amount > 0) {
                balance += amount;
            } else {
                cout << "Invalid amount" << endl;
            }
        }

        void withdraw(float amount) {
            if (amount > 0 && balance - amount >= min_balance) {
                balance -= amount;
                cout << "Withdrawal of " << amount << " is successful." << endl;
            } else {
                cout << "Invalid or insufficient funds for withdrawal" << endl;
            }
        }

        void giveInterest(float interestRate = 3.0) {
            float interest = (balance * interestRate) / 100.0;
            float tax = interest * 0.1;  
            interest -= tax;
            balance += interest;
            totalTaxCollected += tax;
            cout << "Interest of " << interestRate << "% applied, after tax: " << interest << endl;
        }

        void display() {
            cout << "Customer Details:" << endl;
            cout << "Customer Name: " << holder_name << endl;
            cout << "Account Number: " << account_number << endl;
            cout << "Account Type: " << account_type << endl;
            cout << "Balance: " << balance << endl;
        }

        static void display_stat() {
            cout << "Total number of Bank Accounts Created: " << totalAccounts << endl;
            cout << "Total number of Bank Accounts Present: " << totalAccountPresent << endl;
            cout << "Total Amount of Tax collected: " << totalTaxCollected << endl;
        }

        static BankAccount Larger(BankAccount &A, BankAccount &B) {
            return (A.balance > B.balance) ? A : B;
        }
};

int BankAccount::totalAccounts = 0;
int BankAccount::totalAccountPresent = 0;
double BankAccount::totalTaxCollected = 0.0;

int main() {
    BankAccount acc1(1234, "Alice", 5000, 1000);
    BankAccount acc2(5678, "Bob", 3000, 500);

    acc1.accountType("Savings");
    acc2.accountType("Current");

    acc1.display();
    acc2.display();

    acc1.deposit(2000);
    acc1.withdraw(1000);

    acc1.giveInterest();
    acc2.giveInterest(5);  

    acc1.showBalance();
    acc2.showBalance();

    BankAccount larger = BankAccount::Larger(acc1, acc2);
    cout << "The account with the larger balance belongs to: "<<endl;
    larger.display();

    acc1.~BankAccount();

    BankAccount::display_stat();

    return 0;
}
