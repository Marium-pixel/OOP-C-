#include<iostream>
using namespace std;

class LoanHelper {
private:
    const float rate;   
    float loan;         
    int months;         
    float calc_amount;  

public: 
    LoanHelper(float r, float l, int m) : rate(r), loan(l), months(m), calc_amount(0.0f) {}
 
    float calculateAmount() {
        float baseRepayment = loan / months;                
        calc_amount = baseRepayment + (baseRepayment * rate); 
        return calc_amount;
    }
 
    float getRate() const {
        return rate;
    }
};

int main() {
    float loanAmount, interestRate;
    int repaymentMonths;
 
    cout << "Enter the loan amount: ";
    cin >> loanAmount;

    cout << "Enter the number of months to repay the loan: ";
    cin >> repaymentMonths;
 
    do {
        cout << "Enter the interest rate (between 0 and 0.5): ";
        cin >> interestRate;
        if (interestRate < 0 || interestRate > 0.005) {
            cout << "Please enter a valid interest rate between 0 and 0.5%" << endl;
        }
    } while (interestRate < 0 || interestRate > 0.005);
 
    LoanHelper loanHelper(interestRate, loanAmount, repaymentMonths);
 
    float monthlyRepayment = loanHelper.calculateAmount();
    cout << "You have to pay " << monthlyRepayment << " every month for "
         << repaymentMonths << " months to repay your loan." << endl;

    return 0;
}
