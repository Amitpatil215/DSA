#include <bits/stdc++.h>
using namespace std;

void removeChar(char str[], int i, char k)
{
    if (str[i] == '\0')
    {
        return;
    }
    if (str[i] == k)
    {
        for (int j = i; str[j] != '\0'; j++)
        {

            str[j] = str[j + 1];
        }
        return removeChar(str, i, k);
    }
    return removeChar(str, i + 1, k);
}
int main()
{
    char a[] = "Hellos";
    removeChar(a, 0, 'l');
    for (int i = 0; a[i] != '\0'; i++)
    {
        cout << a[i];
    }
    return 0;
}