/* You are building an employee management system. Create a class `Employee` to manage employee
records.
Requirements:
1. Attributes:
 `employeeID` (int)
 `name` (string)
 `department` (string)
 `salary` (double)
2. Define a default constructor that initializes `salary` to `0.0`.
3. Define a parameterized constructor to initialize all attributes.
4. Add methods:
 `giveBonus(double amount)`: Adds the bonus amount to the employee's salary.
 `isManager()`: Returns `true` if the employee's department is "Management".
 `displayDetails()`: Displays the employee's details.
5. Create a few `Employee` objects and test the methods.*/

#include <iostream>
 using namespace std;

class Employee {
    int employeeID;
    string name;
    string department;
    double salary;
    public:


    Employee( int employeeID, string name, string department,double salary ){
        this->employeeID=employeeID;
        this->name=name;
        this->department=department;
        this->salary=salary;

    }
    Employee(){
        salary=0.0;
    }
    void givebonus(double amount){
         
        salary=salary+amount;
        
    }

    bool isManager(){
        if (department=="Management"){
            return true;
        } 
    }
    void DisplayDetails(){
        cout<<"Employee Details: \n";
        cout<<"Employee ID:"<<employeeID<<endl;
        cout<<"Name:"       <<name      <<endl;
        cout<<" Department" <<department<<endl;
        cout<<"Salary"      <<salary    <<endl;
    }



};

int main(){
    Employee e1(1212,"Sam","Manager",45000.00);
    Employee e2(2323,"John","Accountant",9000.50);

    double amount=300.00;

    e1.givebonus(amount);
    e1.isManager();
    e1.DisplayDetails();

    e2.givebonus(amount);
    e2.isManager();
    e2.DisplayDetails();

    return 0;
    
}
 
