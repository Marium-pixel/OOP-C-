/*Imagine developing a comprehensive banking system simulator for a prominent financial institution. In this system, a base class called Account encapsulates essential data members such as accountNumber, balance, accountHolderName, and optionally accountType. It offers member functions like deposit(amount) to add funds, withdraw(amount) to remove funds with proper error checking, calculateInterest() to compute interest based on varying rules, printStatement() to output detailed transaction histories, and getAccountInfo() to retrieve general account details. 
Derived classes like Savings Account, CheckingAccount, and Fixed DepositAccount extend this structure by incorporating specialized data members-such as interestRate and minimumBalance for Savings Account or maturity Date and fixedInterestRate for Fixed DepositAccount. These derived classes override key functions like calculateInterest() and printStatement() to provide account-type-specific functionalities. Additionally, the withdraw() function is overridden in specific accounts to apply different transaction rules, ensuring that each account type follows realistic banking policies while maintaining polymorphic behavior.*/

#include <iostream>
using namespace std;

class Account {
protected:
    int accountNumber;
    string accountName;
    double balance;

public:
    Account(int accNum, string accName, double bal) 
        : accountNumber(accNum), accountName(accName), balance(bal) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << "\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    virtual bool withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            cout << "Withdrawn: $" << amount << "\n";
            return true;
        } else {
            cout << "Insufficient funds or invalid amount.\n";
            return false;
        }
    }

    virtual float calculateInterest() = 0;

    virtual void printStatement() const {
        cout << "Account Statement for " << accountName << ":\n";
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Balance: $" << balance << "\n";
    }

    void getAccountInfo() const {
        cout << "Account Holder: " << accountName << "\n";
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Balance: $" << balance << "\n";
    }

    virtual ~Account() {}
};

class SavingsAccount : public Account {
private:
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(int accNum, string accName, double bal, double rate, double minBal)
        : Account(accNum, accName, bal), interestRate(rate), minimumBalance(minBal) {}

    float calculateInterest() override {
        return balance * interestRate / 100;
    }

    bool withdraw(double amount) override {
        if (balance - amount < minimumBalance) {
            cout << "Cannot withdraw. Minimum balance requirement not met.\n";
            return false;
        }
        return Account::withdraw(amount);
    }

    void printStatement() const override {
        Account::printStatement();
        cout << "Interest Rate: " << interestRate << "%\n";
        cout << "Minimum Balance: $" << minimumBalance << "\n";
    }
};

class CheckingAccount : public Account {
private:
    double overdraftLimit;

public:
    CheckingAccount(int accNum, string accName, double bal, double overdraft)
        : Account(accNum, accName, bal), overdraftLimit(overdraft) {}

    bool withdraw(double amount) override {
        if (amount > balance + overdraftLimit) {
            cout << "Withdrawal exceeds overdraft limit.\n";
            return false;
        }
        balance -= amount;
        cout << "Withdrawn: $" << amount << " (Overdraft may apply)\n";
        return true;
    }

    void printStatement() const override {
        Account::printStatement();
        cout << "Overdraft Limit: $" << overdraftLimit << "\n";
    }
};

class FixedDepositAccount : public Account {
private:
    string maturityDate;
    double fixedInterestRate;

public:
    FixedDepositAccount(int accNum, string accName, double bal, string maturity, double rate)
        : Account(accNum, accName, bal), maturityDate(maturity), fixedInterestRate(rate) {}

    float calculateInterest() override {
        return balance * fixedInterestRate / 100;
    }

    bool withdraw(double amount) override {
        cout << "Withdrawals not allowed before maturity date: " << maturityDate << "\n";
        return false;
    }

    void printStatement() const override {
        Account::printStatement();
        cout << "Fixed Interest Rate: " << fixedInterestRate << "%\n";
        cout << "Maturity Date: " << maturityDate << "\n";
    }
};

int main() {
    SavingsAccount sa(123456, "Alice", 1500.0, 3.5, 500.0);
    CheckingAccount ca(789012, "Bob", 1000.0, 200.0);
    FixedDepositAccount fda(345678, "Charlie", 5000.0, "2026-12-31", 5.0);

    cout << "\n--- Account Information ---\n";
    sa.getAccountInfo();
    ca.getAccountInfo();
    fda.getAccountInfo();

    cout << "\n--- Deposits & Withdrawals ---\n";
    sa.deposit(200);
    sa.withdraw(800);

    ca.withdraw(1100);
    fda.withdraw(1000);

    cout << "\n--- Interest Calculation ---\n";
    cout << "Savings Interest: $" << sa.calculateInterest() << "\n";
    cout << "Fixed Deposit Interest: $" << fda.calculateInterest() << "\n";

    cout << "\n--- Statements ---\n";
    sa.printStatement();
    ca.printStatement();
    fda.printStatement();

    return 0;
}

 
