#include <iostream>
using namespace std;

class Student
{
public:
    int rollNumber;

    //private:
    int age;
    void display()
    {
        cout << age << " "
             << "age" << endl;
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
