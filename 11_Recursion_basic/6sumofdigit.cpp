#include <bits/stdc++.h>
using namespace std;

int sumOfDigit(int n)
{
    if (n == 0)
    {
        return 0;
    }
    //recursive case
    int smallOutput = sumOfDigit(n / 10);
    //calculation
    int lastDigit = n % 10;
    return smallOutput + lastDigit;
}

int main()
{
    cout << sumOfDigit(12345);
    return 0;
}