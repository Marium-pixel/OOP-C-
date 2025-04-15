#include <iostream>
#include <string>

using namespace std;

// Abstract  
class PaymentMethod {
public:
    virtual bool processPayment(double amount) = 0;
    virtual ~PaymentMethod() {}
};
 
class CreditCard : public PaymentMethod {
private:
    string cardNumber;

public:
    CreditCard(const string& number) : cardNumber(number) {}

    bool processPayment(double amount) override {
        if (cardNumber.length() == 16) {
            cout << "Processing credit card payment of $" << amount << "...\n";
            cout << "Credit card " << cardNumber << " approved.\n";
            return true;
        } else {
            cout << "Invalid credit card number. Payment failed.\n";
            return false;
        }
    }
};
 
class DigitalWallet : public PaymentMethod {
private:
    double balance;

public:
    DigitalWallet(double initialBalance) : balance(initialBalance) {}

    bool processPayment(double amount) override {
        if (amount <= balance) {
            balance -= amount;
            cout << "Processing digital wallet payment of $" << amount << "...\n";
            cout << "Payment successful. Remaining balance: $" << balance << endl;
            return true;
        } else {
            cout << "Insufficient funds. Payment failed.\n";
            return false;
        }
    }
};

int main() { 
    CreditCard cc("1234567890123456");
    DigitalWallet wallet(100.0);

    cout << "--- Attempting Credit Card Payment ---\n";
    cc.processPayment(50.0);

    cout << "\n--- Attempting Digital Wallet Payment ---\n";
    wallet.processPayment(30.0);

    cout << "\n--- Attempting Wallet Overdraft ---\n";
    wallet.processPayment(80.0);

    return 0;
}
