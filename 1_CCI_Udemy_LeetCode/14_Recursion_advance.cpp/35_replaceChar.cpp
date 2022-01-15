#include <bits/stdc++.h>
using namespace std;

void replaceChar(char str[], int i, char k, char m)
{
    if (i == -1)
    {
        return;
    }
    if (str[i] == k)
    {
        str[i] = m;
    }
    return replaceChar(str, i - 1, k, m);
}
int main()
{
    char a[] = "Hello";
    replaceChar(a, 4, 'l', 'x');
    for (int i = 0; a[i] != '\0'; i++)
    {
        cout << a[i];
    }
    return 0;
}