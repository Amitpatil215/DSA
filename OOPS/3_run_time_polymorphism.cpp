/*
Run time polymorphosm can be achieved using
1. function/ method overriding
2. can be acheived in inheritance only
*/

#include <bits/stdc++.h>
using namespace std;
class Animal {
   public:
    void speak() { cout << "Speaking.." << endl; }
};

class Dog : public Animal {
   public:
    void speak() { cout << "Barking.." << endl; }
};

int main() {
    Dog d;
    d.speak(); // Barking..
    return 0;
}
