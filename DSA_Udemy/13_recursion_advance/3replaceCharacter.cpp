#include <bits/stdc++.h>
using namespace std;

void replaceChar(char arr[], char toReplace, char replaceWith)
{
    //base case
    if (arr[0] == '\0')
    {
        return;
    }

    if (arr[0] == toReplace)
    {
        arr[0] = replaceWith;
    }

    return replaceChar(arr + 1, toReplace, replaceWith);
}

int main()
{
    char arr[] = "Hello Amit Patil";
    replaceChar(arr, 'l', 'K');
    for (int i = 0; i < 16; i++)
    {
        cout << arr[i];
    }
    return 0;
}