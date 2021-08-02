#include <bits/stdc++.h>
using namespace std;

void printPermutaions(char str[], int i = 0)
{
    if (str[i] == '\0')
    {
        cout << str << endl;
        return;
    }

    for (int j = i; str[j] != '\0'; j++)
    {
        swap(str[i], str[j]);
        printPermutaions(str, i + 1);
        swap(str[j], str[i]);
    }
}

int main()
{
    char str[] = "ABC";
    printPermutaions(str);
}