#include <iostream>
#include "student.cpp"
using namespace std;
int main()
{
    // statically creating objects
    Student s3;
    s3.rollNumber = 12;
    s3.age = 52;
    cout << s3.rollNumber << endl;

    // Dynamically creating objects
    Student *s6 = new Student;
    s6->age = 18;
    (*s6).rollNumber = 30;
    cout << (*s6).age << endl;
    cout << (*s6).rollNumber << endl;

    s3.display();


    //calling parametrized constructor
    cout<<"Parametrized constructor demo"<<endl;
    Student s5(20);
    s5.display();
    return 0;
}