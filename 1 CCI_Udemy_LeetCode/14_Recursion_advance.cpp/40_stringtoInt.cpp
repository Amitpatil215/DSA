#include <bits/stdc++.h>
using namespace std;

int stringToInt(string str)
{
    if (str.length() == 0)
    {
        return 0;
    }

    int no = str[0] - '0';
    int len = str.length();
    return (no * pow(10, len - 1)) + stringToInt(str.substr(1));
}

int main()
{
    cout << stringToInt("4321");
    return 0;
}