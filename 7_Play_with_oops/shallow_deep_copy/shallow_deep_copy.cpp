#include <iostream>
using namespace std;

class Student
{
    int age;
    char *name;

public:
    Student(int age, char *name)
    {
        this->age = age;
        this->name = name;
    }

    void display()
    {
        cout << name << " " << age << endl;
    }
};

int main()
{
    char name[] = "abcd";
    Student s1(20, name);
    s1.display();

    name[3] = 'e';
    Student s2(30, name);
    s2.display();

    s1.display();
    return 0;
}