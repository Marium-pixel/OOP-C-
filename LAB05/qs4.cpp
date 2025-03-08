#include<iostream>
using namespace std;

class BankAccount{
    private:
    int accountNumber;
    string accountHolderName;
    double balance;
    public:
    BankAccount(int accNum, string accName, double balance){
        accountNumber=accNum;
        accountHolderName=accName;
        this-> balance=balance;
    }

    void deposit(double amount){
        balance+=amount;

    }

    void withdraw(double amount){
         
        if(balance>=amount){
            balance= balance -amount;
            cout<<"amount withdrawn successfully";
        }
        else if(balance < amount){
            cout<<"insuffiecient account balance";
        }
    }

    void display(){
        cout<<"here are the account details: \n";
        cout<<"account number :"    <<accountNumber     <<endl;
        cout<<"account holder's name"<<accountHolderName<<endl;
        cout<<"account balance:     "<<balance          <<endl;
    }



};

int main(){
    BankAccount accounts[3]={
        BankAccount(12889,"jenny",9999.0),
        BankAccount(75757,"sam",8288.0),
        BankAccount(10101,"Ali",1000.0),

    };

    for (int i=0; i<3; i++){
        cout<<"here are the account details: \n";
        accounts[i].display();

        accounts[i].deposit(500.0);
        accounts[i].display();

        accounts[i].withdraw(200.0);
        accounts[i].display();

    }

}
