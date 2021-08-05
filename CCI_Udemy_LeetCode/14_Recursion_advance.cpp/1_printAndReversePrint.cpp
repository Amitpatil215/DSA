#include <bits/stdc++.h>
using namespace std;

void reversePrint(string s, int i)
{
    if (i == -1)
    {
        return;
    }

    cout << s[i];
    return reversePrint(s, i - 1);
}
void print(string s)
{
    if (s.size() == 0)
    {
        return;
    }
    cout << s[0];
    return print(s.substr(1));
}
int main()
{
    string str = "Hello";
    reversePrint(str, str.length() - 1);
    print(str);
    return 0;
}