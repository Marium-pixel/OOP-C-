#include <iostream>
#include <string>

using namespace std;

class Account {
private:
    string accountNumber;
    string accountHolder;
    double balance;

public:
    Account(string accNum, string holder, double bal) : accountNumber(accNum), accountHolder(holder), balance(bal) {}

    Account operator+(const Account &acc) {
        return Account("N/A", "Total Balance", this->balance + acc.balance);
    }

    Account &operator-=(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient funds for transfer!" << endl;
        }
        return *this;
    }

    bool operator>(const Account &acc) const {
        return this->balance > acc.balance;
    }

    friend ostream &operator<<(ostream &os, const Account &acc) {
        os << "Account Number: " << acc.accountNumber << " | Holder: " << acc.accountHolder
           << " | Balance: $" << acc.balance;
        return os;
    }

    void setBalance(double newBalance) {
        balance = newBalance;
    }

    double getBalance() const {
        return balance;
    }

    string getHolder() const {
        return accountHolder;
    }
};

int main() {
    Account acc1("101", "Shafique Rehman", 5000);
    Account acc2("102", "Talha", 3000);

    cout << "Performing:\n";
    cout << "1. Adding Account 1 and Account 2 balances.\n";
    cout << "2. Transferring 2000 from Account 1 to Account 2.\n";
    cout << "3. Checking which account has a higher balance.\n";
    cout << "4. Displaying final account details.\n\n";

    Account totalBalance = acc1 + acc2;
    cout << "Total Balance (After Addition): " << totalBalance.getBalance() << endl;

    acc1 -= 2000;
    acc2.setBalance(acc2.getBalance() + 2000);

    cout << "After Transfer:\n";
    cout << "Shafique Reh's New Balance: $" << acc1.getBalance() << endl;
    cout << "Talha's New Balance: $" << acc2.getBalance() << endl;

    cout << "Comparison:\n";
    if (acc1 > acc2) {
        cout << acc1.getHolder() << " has more balance than " << acc2.getHolder() << "." << endl;
    } else {
        cout << acc1.getHolder() << " has less balance than " << acc2.getHolder() << "." << endl;
    }

    cout << "Final Account Details:\n" << acc1 << endl << acc2 << endl;

    return 0;
}
