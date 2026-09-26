#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>   
using namespace std;
class Person
{
private:
    char name[64];
    int age;
    char address[64];
    float basic;
    float hra;
    float da;
    float ta;
    float totalSalary;
public:
    Person()
    {
        strcpy(name, "");
        age = 0;
        strcpy(address, "");
        basic = 0;
        hra = 0;
        da = 0;
        ta = 0;
        totalSalary = 0;
    }
    Person(const char n[], int a, const char addr[], float b)
    {
        strcpy(name, n);
        age = a;
        strcpy(address, addr);
        basic = b;
        hra = basic * 0.20f;   
        da  = basic * 0.10f;   
        ta  = basic * 0.05f;   
        totalSalary = basic + hra + da + ta;
    }
    int getAge() const
    {
        return age;
    }
    const char* getName() const
    {
        return name;
    }
    void displaySalarySlip() const
    {
        cout << fixed << setprecision(2);
        cout << "\n----------------------------------------";
        cout << "\n           SALARY SLIP";
        cout << "\n----------------------------------------";
        cout << "\nName         : " << name;
        cout << "\nAge          : " << age;
        cout << "\nAddress      : " << address;
        cout << "\n----------------------------------------";
        cout << "\nBasic Salary : " << basic;
        cout << "\nHRA          : " << hra;
        cout << "\nDA           : " << da;
        cout << "\nTA           : " << ta;
        cout << "\n----------------------------------------";
        cout << "\nTotal Salary : " << totalSalary;
        cout << "\n----------------------------------------\n";
    }
};
inline int getYoungestIndex(Person p[], int n)
{
    int youngest = 0;
    for (int i = 1; i < n; i++)
    {
        if (p[i].getAge() < p[youngest].getAge())
            youngest = i;
    }
    return youngest;
}
inline int getEldestIndex(Person p[], int n)
{
    int eldest = 0;
    for (int i = 1; i < n; i++)
    {
        if (p[i].getAge() > p[eldest].getAge())
            eldest = i;
    }
    return eldest;
}
int main()
{
    const int SIZE = 10;
    Person p[SIZE] =
    {
        Person("Rahul",  25, "Kolkata",   25000),
        Person("Amit",   30, "Delhi",     30000),
        Person("Ravi",   22, "Mumbai",    28000),
        Person("Sumit",  35, "Pune",      40000),
        Person("Ankit",  28, "Patna",     32000),
        Person("Rohit",  24, "Kolkata",   27000),
        Person("Vikas",  40, "Delhi",     45000),
        Person("Karan",  26, "Jaipur",    29000),
        Person("Suresh", 32, "Chennai",   35000),
        Person("Raj",    21, "Bangalore", 26000)
    };
    int youngest = getYoungestIndex(p, SIZE);
    int eldest   = getEldestIndex(p, SIZE);
    cout << "\nYOUNGEST PERSON";
    cout << "\nName : " << p[youngest].getName();
    cout << "\nAge  : " << p[youngest].getAge() << "\n";
    cout << "\nELDEST PERSON";
    cout << "\nName : " << p[eldest].getName();
    cout << "\nAge  : " << p[eldest].getAge() << "\n";
    cout << "\n\nSALARY SLIPS OF ALL EMPLOYEES\n";
    for (int i = 0; i < SIZE; i++)
    {
        p[i].displaySalarySlip();
    }
    system("pause");   
    return 0;
}