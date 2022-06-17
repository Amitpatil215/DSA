#include <bits/stdc++.h>
using namespace std;

//it is like a scope
// where all the functions are declered (i.e. in the std)
namespace amit
{
    int age = 70;
}

int main()
{
    int age = 20;
    cout << age << endl;
    cout << amit::age << endl;
    return 0;
}