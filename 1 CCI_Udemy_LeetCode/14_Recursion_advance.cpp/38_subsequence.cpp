#include <bits/stdc++.h>
using namespace std;

void printSub(string str, string out)
{
    if (str.length() == 0)
    {
        cout << out << endl;
        return;
    }

    //exclude
    printSub(str.substr(1), out);
    //include
    printSub(str.substr(1), out + str[0]);
}

int main()
{
    string s = "ABC";
    printSub(s, "");

    return 0;
}