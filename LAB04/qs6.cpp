/* Scenario: A bank wants to develop a system for managing customer accounts. The system
should allow customers to:
1. Create a new account with an account number, owner’s name, and initial balance
(default balance is 0 if not provided).
2. Deposit money into their account.
3. Withdraw money from their account, ensuring they cannot withdraw more than the
available balance.
4. Display account details including account number, owner’s name, and current balance.
Your task is to implement a C++ program that fulfills these requirements.*/

#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string ownerName;
    double balance;

public:
    BankAccount(int accountNumber, string ownerName, double balance = 0.0) {
        this->accountNumber = accountNumber;
        this->ownerName = ownerName;
        this->balance = balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Deposit amount must be greater than zero." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount <= balance && amount > 0) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else if (amount > balance) {
            cout << "Insufficient balance. Withdrawal denied." << endl;
        } else {
            cout << "Withdrawal amount must be greater than zero." << endl;
        }
    }

    void displayDetails() const {
        cout << "\nAccount Details:\n";
        cout << "Account Number: " << accountNumber << endl;
        cout << "Owner's Name: " << ownerName << endl;
        cout << "Current Balance: " << balance << endl;
    }

    int getAccountNumber() const {
        return accountNumber;
    }
};

int main() {
    BankAccount account1(1001, "Alice", 500.0);
    BankAccount account2(1002, "Bob");

    int choice, accountChoice;
    double amount;

    do {
        cout << "\n*** Bank System ***\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Display Account Details\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1 || choice == 2 || choice == 3) {
            cout << "Choose account (1 for Alice, 2 for Bob): ";
            cin >> accountChoice;
        }

        switch (choice) {
            case 1: 
                if (accountChoice == 1) {
                    cout << "Enter deposit amount for Alice: ";
                    cin >> amount;
                    account1.deposit(amount);
                } else if (accountChoice == 2) {
                    cout << "Enter deposit amount for Bob: ";
                    cin >> amount;
                    account2.deposit(amount);
                }
                break;

            case 2: 
                if (accountChoice == 1) {
                    cout << "Enter withdrawal amount for Alice: ";
                    cin >> amount;
                    account1.withdraw(amount);
                } else if (accountChoice == 2) {
                    cout << "Enter withdrawal amount for Bob: ";
                    cin >> amount;
                    account2.withdraw(amount);
                }
                break;

            case 3: 
                if (accountChoice == 1) {
                    account1.displayDetails();
                } else if (accountChoice == 2) {
                    account2.displayDetails();
                }
                break;

            case 4:
                cout << "Exiting the system. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
