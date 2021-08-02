#include <iostream>
#include "../6_OOPS/Student.cpp"
using namespace std;

int main()
{
    Student s1;          // default constructor called
    Student s2(100);     //one parametrized Constructor called
    Student s3(10, 100); //two parametrized Constructor called
    Student s4(s3);      // copy constructor called
    s1 = s2;             // copy assignment operator
    Student s5 = s3;     // copy constructor is called
    return 0;
}