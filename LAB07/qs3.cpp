#include <iostream>
#include <string>

using namespace std;

class Currency {
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate;

public:
    Currency(double amt, string code, string symbol, double rate = 1.0)
        : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

    virtual double convertToBase() const {
        return amount * exchangeRate;
    }

    virtual double convertTo(const Currency& target) const {
        double baseAmount = convertToBase();
        return baseAmount / target.exchangeRate;
    }

    virtual void displayCurrency() const {
        cout << amount << " " << currencySymbol << " (" << currencyCode << ")" << endl;
    }
};

class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}

    double convertToBase() const override {
        return amount;
    }

    void displayCurrency() const override {
        cout << "Dollar: ";
        Currency::displayCurrency();
    }
};

class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, "EUR", "€", 0.85) {}

    void displayCurrency() const override {
        cout << "Euro: ";
        Currency::displayCurrency();
    }
};

class Rupee : public Currency {
public:
    Rupee(double amt) : Currency(amt, "PKR", "₨", 0.0056) {}

    void displayCurrency() const override {
        cout << "Rupee: ";
        Currency::displayCurrency();
    }
};

int main() {
    Dollar dollar(100);
    Euro euro(85);
    Rupee rupee(7000);

    dollar.displayCurrency();
    euro.displayCurrency();
    rupee.displayCurrency();

    double euroFromDollar = dollar.convertTo(euro);
    cout << "Converted " << dollar.convertToBase() << " USD to "
         << euroFromDollar << " EUR." << endl;

    double rupeeFromEuro = euro.convertTo(rupee);
    cout << "Converted " << euro.convertToBase() << " EUR to "
         << rupeeFromEuro << " PKR." << endl;

    return 0;
}
