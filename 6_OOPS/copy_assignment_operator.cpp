#include <iostream>
#include "student.cpp"
using namespace std;
int main()
{
    Student s1(10, 100);
    Student s2(20, 200);

    s2 = s1;

    Student *s3 = new Student(30, 300);
    *s3 = s1;

    s3->display();
    s2.display();

    /// static memories is deleted automatically
    /// for dynamic memory we have to destruct manually
    delete s3;
}