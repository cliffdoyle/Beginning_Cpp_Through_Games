#include <iostream>

using namespace std;

class Employee{
    public:
    string Name;
    string Company;
    int Age;

    void printName()
    {
        cout  << Name << endl;
         cout  << Age << endl;
         cout << Company << endl;
    }

    Employee(string name,string company, int age)
    {
        Name = name;
        Company = company;
        if (age >=20){
            Age = age;

        }else {

              cout << "\n under age\n";
          }
    
};
};

int main()
{
    Employee emplyee1 = Employee("cliff","Gamer_w",13);
    // emplyee1.Name = "cliff";
    // emplyee1.Age = 33;
    cout << "\nEmployee Details:\n";
    emplyee1.printName();
}