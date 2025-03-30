#include <iostream>
#include <string>

using namespace std;

class BankAccount {
protected:
    string accountNumber;
    double balance;

public:
    BankAccount(const string& accNumber, double initialBalance)
        : accountNumber(accNumber), balance(initialBalance) {}

    virtual double calculateInterest() = 0;

    virtual string deposit(double amount, const string& method) {
        balance += amount;
        return "Deposit successful.";
    }

    virtual string withdraw(double amount) {
        if (amount > balance) {
            return "Error: Insufficient funds.";
        }
        balance -= amount;
        return "Withdrawal successful.";
    }

    double getBalance() const {
        return balance;
    }

    double operator+(const BankAccount& other) const {
        return balance + other.balance;
    }

    string operator-(double amount) {
        if (amount > balance) {
            return "Error: Insufficient funds.";
        }
        balance -= amount;
        return "Withdrawal successful.";
    }

    double operator*(double interestRate) {
        balance += balance * (interestRate / 100);
        return balance;
    }

    double operator/(int numPayments) {
        if (numPayments <= 0) {
            return -1;
        }
        return balance / numPayments;
    }
};

class SavingsAccount : public BankAccount {
public:
    static constexpr double interestRate = 5.0;

    SavingsAccount(const string& accNumber, double initialBalance)
        : BankAccount(accNumber, initialBalance) {}

    double calculateInterest() override {
        return balance * (interestRate / 100);
    }

    string deposit(double amount, const string& method) override {
        if (method != "cash" && method != "check" && method != "online") {
            return "Error: Invalid deposit method.";
        }
        if (method == "check") {
            cout << "Check deposit pending clearance." << endl;
        } else if (method == "online") {
            cout << "Online transfer successful." << endl;
        }
        return BankAccount::deposit(amount, method);
    }

    string withdraw(double amount) override {
        if (balance - amount < 500) {
            return "Error: Cannot withdraw, balance must remain above $500.";
        }
        return BankAccount::withdraw(amount);
    }
};

class CurrentAccount : public BankAccount {
public:
    CurrentAccount(const string& accNumber, double initialBalance)
        : BankAccount(accNumber, initialBalance) {}

    double calculateInterest() override {
        return 0;
    }

    string deposit(double amount, const string& method) override {
        if (method != "cash" && method != "check" && method != "online") {
            return "Error: Invalid deposit method.";
        }
        if (method == "check") {
            cout << "Check deposit pending clearance." << endl;
        } else if (method == "online") {
            cout << "Online transfer successful." << endl;
        }
        return BankAccount::deposit(amount, method);
    }

    string withdraw(double amount) override {
        if (amount > balance + 1000) {
            return "Error: Overdraft limit exceeded.";
        }
        return BankAccount::withdraw(amount);
    }
};

int main() {
    SavingsAccount savings("SA123", 1000);
    CurrentAccount current("CA123", 2000);

    cout << savings.deposit(200, "cash") << endl;
    cout << "Savings Account Balance after deposit: $" << savings.getBalance() << endl;

    cout << current.deposit(300, "online") << endl;
    cout << "Current Account Balance after deposit: $" << current.getBalance() << endl;

    cout << savings.withdraw(600) << endl;
    cout << "Savings Account Balance after withdrawal: $" << savings.getBalance() << endl;

    cout << current.withdraw(2500) << endl;
    cout << "Current Account Balance after withdrawal: $" << current.getBalance() << endl;

    double savingsInterest = savings.calculateInterest();
    cout << "Savings Account Interest: $" << savingsInterest << endl;

    savings * SavingsAccount::interestRate;
    cout << "Savings Account Balance after interest: $" << savings.getBalance() << endl;

    double totalBalance = savings + current;
    cout << "Total Balance of both accounts: $" << totalBalance << endl;

    double installments = savings / 5;
    if (installments == -1) {
        cout << "Error: Number of payments must be positive." << endl;
    } else {
        cout << "Equal installment payments from Savings Account: $" << installments << endl;
    }

    return 0;
}
