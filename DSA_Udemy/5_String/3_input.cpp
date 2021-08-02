#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s2;
    getline(cin, s2);
    cout << s2 << endl;

    // Substring
    string s3 = s2.substr(2);
    cout << s3 << endl;

    // find
    int index = s3.find("a");

    cout << index << endl;

    // to string
    int a = 1234;
    //! string b=to_string(a);
    //! cout<<b;

    // cast string to int
    int num=atoi("22");
    cout<<num;
    return 0;
}