#include<bits/stdc++.h>
using namespace std;

class Bank_Account {
    private:
        string customer_name;
        int account_number;
        string account_type;
        int balance;
    public:
        
        Bank_Account() : balance(0) {}

        
        void customerDetails(string name, int ac_num){
            customer_name = name;
            account_number = ac_num;
        }

        
        void accountType(string type){
            if(type == "Current") 
                account_type = "Current";
            else if (type == "Savings") 
                account_type = "Savings";
            else {
                cout << "Invalid account type" << endl;
                return;}
        }

        
        void displayBalance(){
            cout << "Balance: " << balance << endl;
        }

        
        void deposit(int amount) {
            balance += amount;
        }

        
        void withdraw(int amount) {
            if (amount > balance){
                cout << "Insufficient funds" << endl;
                return;
            }
            else{
                balance -= amount;
                cout << "Withdrawal of " << amount << " is successful." << endl;
            }
        }

        // Function to display customer details
        void display(){
            cout << "Customer Details :" << endl;
            cout << "Customer Name: " << customer_name << endl;
            cout << "Account Number: " << account_number << endl;
            cout << "Account Type: " << account_type << endl;
            cout << "Balance: " << balance << endl;
        }
};

int main(){
    Bank_Account account;
    account.customerDetails("Alice", 987654);
    account.accountType("Savings");
    account.deposit(2000);
    account.display();
    account.withdraw(1500);
    account.displayBalance();
    return 0;
}
    
