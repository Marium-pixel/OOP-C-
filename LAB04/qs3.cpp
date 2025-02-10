 /*You are building a bank account management system. Create a class `Account` to manage bank
accounts.
 Requirements:
1. Attributes:
 `accountNumber` (string)
 `accountHolderName` (string)
 `balance` (double)
2. Define a default constructor that initializes `balance` to `0.0`.
3. Define a parameterized constructor to initialize all attributes.
4. Add methods:
 `deposit(double amount)`: Adds the amount to the balance.
 `withdraw(double amount)`: Deducts the amount from the balance (if sufficient funds are
available).
 `checkBalance()`: Displays the current balance.
5. Create a few `Account` objects and test the methods.
*/

#include <iostream>
using namespace std;

class Account {
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    Account(string accountNumber, string accountHolderName, double balance) {
        this->accountNumber = accountNumber;
        this->accountHolderName = accountHolderName;
        this->balance = balance;
    }

    Account() {
        balance = 0.0;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Amount deposited successfully!\n";
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Amount withdrawn successfully!\n";
        } else {
            cout << "Insufficient balance!\n";
        }
    }

    void checkBalance() {
        cout << "Current balance: " << balance << endl;
    }

    string getAccountNumber() {
        return accountNumber;
    }
};

// Function to find account by account number
Account* findAccount(Account accounts[], int size, string accountNumber) {
    for (int i = 0; i < size; i++) {
        if (accounts[i].getAccountNumber() == accountNumber) {
            return &accounts[i];
        }
    }
    return nullptr;
}

int main() {
    Account accounts[] = {
        Account("1234", "Hafsa", 90090),
        Account("7878", "Armeen", 200),
        Account("6004", "Mariumali", 71000),
        Account("4747", "Ariza", 1111.75)
    };
    int numAccounts = 4;

    while (true) {
        cout << "\nChoose an option:\n";
        cout << "1. Deposit money\n";
        cout << "2. Withdraw money\n";
        cout << "3. Check balance\n";
        cout << "4. Exit\n";
        int choice;
        cin >> choice;

        if (choice == 4) break;

        string accountNumber;
        cout << "Enter Account Number: ";
        cin >> accountNumber;

        Account* account = findAccount(accounts, numAccounts, accountNumber);
        if (account == nullptr) {
            cout << "Invalid account number!\n";
            continue;
        }

        double amount;
        switch (choice) {
            case 1:
                cout << "Enter deposit amount: ";
                cin >> amount;
                account->deposit(amount);
                break;
            case 2:
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                account->withdraw(amount);
                break;
            case 3:
                account->checkBalance();
                break;
            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}
