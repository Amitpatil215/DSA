/*
This type of error occurs in multiple inheritance
also known as diamond problem
 */
#include <bits/stdc++.h>
using namespace std;

class A {
   public:
    func() { cout << "Hello from class A"; }
};

class B {
   public:
    func() { cout << "Hello from class B"; }
};

class C : public A, public B {};
int main() {
    C c;
    // this will say request for member func is ambiguous
    // cause it couldn't deferentiate between the calls from Classs A and B
    // c.func();

    // instead use scope resolution operator
    c.A::func();  // calls class a function

    return 0;
}