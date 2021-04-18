#include <iostream>
using namespace std;

class Student
{
public:
    int rollNumber;

    int age;

    // default constructor
    Student()
    {
        cout << "our constructor called" << endl;
    }

    // parametrized constructor
    Student(int r)
    {
        rollNumber = r;
    }
    Student(int age, int rollNumber)
    {
        cout << "this " << this << endl;
        this->age = age;
        this->rollNumber = rollNumber;
    }

    // default destructor
    ~Student()
    {
        cout << "destructor called"<< endl;
    }

    void display()
    {
        cout << age << " "
             << "age" << endl;
        cout << rollNumber << " "
             << "rollNumber" << endl;
    }

    void setAge(int age)
    {
        age = age;
    }
    int getAge()
    {
        return age;
    }
};
