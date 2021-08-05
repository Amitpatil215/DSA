#include <bits/stdc++.h>
using namespace std;

void removeDuplicares(char a[], int i)
{
    if (a[i + 1] == '\0')
    {
        return;
    }
    if (a[i] == a[i + 1])
    {
        for (int j = i; a[j] != '\0'; j++)
        {
            a[j] = a[j + 2];
            // if we got '\0' no need to shift further chracters
            if (a[j] == '\0')
                break;
        }
        return removeDuplicares(a, i - 1);
    }
    return removeDuplicares(a, i + 1);
}
int main()
{
    char a[] = "acbbcca";

    removeDuplicares(a, 0);
    for (int i = 0; a[i] != '\0'; i++)
    {
        cout << a[i];
    }
    return 0;
}