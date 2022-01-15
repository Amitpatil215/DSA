#include <bits/stdc++.h>
using namespace std;

void print(char arr[])
{
    //base case
    if (arr[0] == '\0')
    {
        return;
    }
    cout << arr[0];
    print(arr + 1);
}

void printReverse(char arr[])
{
    //base case
    if (arr[0] == '\0')
    {
        return;
    }
    printReverse(arr + 1);
    cout << arr[0];
}

int main()
{
    char arr[] = "Hello";
    print(arr);
    cout << endl;
    printReverse(arr);
    return 0;
}