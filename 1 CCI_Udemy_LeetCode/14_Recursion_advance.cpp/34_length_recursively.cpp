#include <bits/stdc++.h>
using namespace std;

int len(char str[])
{
    if (str[0] == '\0')
    {
        return 0;
    }
    return 1 + len(str + 1);
}
int main()
{
    char a[] = "Hello";
    cout << len(a);
    return 0;
}