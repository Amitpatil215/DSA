#include <bits/stdc++.h>
using namespace std;

int multiply(int m, int n)
{
    //base case
    if (n == 0)
    {
        return 0;
    }
    //recursive case
    int smallMultiplication = multiply(m, n - 1);
    //calculation
    return smallMultiplication + m;
}

int main()
{
    cout << multiply(10, 5);
    return 0;
}