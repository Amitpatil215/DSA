#include <bits/stdc++.h>
using namespace std;

int countZero(int n)
{
    //base case
    if (n == 0)
    {
        return 0;
    }

    //recursive case
    int smallOutput = countZero(n / 10);

    //calculation
    int lastdigit = n % 10;
    return lastdigit == 0 ? smallOutput + 1 : smallOutput;
}

int main()
{
    cout << countZero(2059004000);
    return 0;
}