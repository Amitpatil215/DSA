#include <bits/stdc++.h>
using namespace std;

int length(char arr[])
{
    if (arr[0] == '\0')
    {
        return 0;
    }

    return 1 + length(arr + 1);
}

int convertToInt(char input[], int n)
{
    //base case
    if (n == 0)
    {
        return 0;
    }
    int smallAns = convertToInt(input, n - 1);
    int lastDigit = input[n - 1] - '0';
    return (smallAns * 10) + lastDigit;
}

int main()
{
    char str[] = "12345";
    int n = length(str);
    cout << convertToInt(str, n);
    return 0;
}