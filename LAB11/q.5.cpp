#include <iostream>
#include <string>
#include <exception>
using namespace std;

class Insufficientfundsexception : public exception 
{
    private:
        string message;

    public:
        Insufficientfundsexception(double deficit) 
        {
            message = "InsufficientFundsException - Deficit: $" + to_string(deficit);
        }

        const char* what() const noexcept override 
        {
            return message.c_str();
        }
};

template <typename T>
class BankAccount 
{
    private:
        T balance;
        
    public:
        BankAccount(T b) : balance(b) {}

        void withdraw(T amount) 
        {
            if (amount > balance)
                throw Insufficientfundsexception(static_cast<double>(amount - balance));
            balance = balance - amount;
        }

        T getBalance() const 
        {
            return balance;
        }
};

int main() 
{
    BankAccount<double> account(500.00);
    cout << "Balance: $" << account.getBalance() << endl;

    try 
    {
        account.withdraw(600.00);
    }
    catch (const exception& e) 
    {
        cout << "Withdraw $600: " << e.what() << endl;
    }
}
