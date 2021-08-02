#include <iostream>
using namespace std;

int main()
{
    string s1="abc";
    cout<<s1;

    // Storing string dynamically
    string *sp=new string;
    *sp="mno";

    cout<<sp<<endl;
    cout << *sp << endl;
    return 0;
}