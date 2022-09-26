/*
Compile time polymorphosm can be achieved using
1. Function Overloading
2. Operating Overloading
*/

#include <bits/stdc++.h>
using namespace std;

class A {
   public:
    int val;
    // fucntion overloading
    sayHello() { cout << "Hello" << endl; }
    sayHello(string name) { cout << "Hello " << name << endl; }
    // operator overloading
    void operator+(A obj) {
        int val1 = this->val;
        int val2 = obj.val;
        cout << "Im subtracting hehe " << val2 - val1 << endl;
    }
};

int main() {
    A a;

    a.sayHello();        // calls class a function
    a.sayHello("Amit");  // calls class a function

    // example showing operator overlaoding
    A a1, a2;
    a1.val = 3;
    a2.val = 10;
    a1 + a2;

    return 0;
}