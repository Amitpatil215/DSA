#include <iostream>
#include "student.cpp"
using namespace std;
int main()
{
    Student s1(10, 100);
    Student s2(s1); // copy constructor get called
    s1.display();
    s2.display();

    Student *s3 = new Student(20, 200);
    cout << "s3 ";

    Student s4(*s3);
    s3->display();
    s4.display();
}