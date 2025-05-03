#include <iostream>
using namespace std;

class Invalidvalueexception : public exception
{
    public:
        Invalidvalueexception() {}

        const char* what() const noexcept override
        {
            return "invalid age";
        }
};

void ValidateAge(int age)
{
    if (age < 0 || age > 120)
    {
        throw Invalidvalueexception();
}
}
int main()
{
    int age;
    cout << "enter age: " << endl;
    cin >> age;
    try
    {
        ValidateAge(age);
        cout << "Age is " << age << endl;
    }
    catch(const exception& e)
    {
        cout << "Exception at: " << e.what() << endl;
    }
}
