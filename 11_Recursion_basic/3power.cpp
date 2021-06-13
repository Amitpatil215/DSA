#include <bits/stdc++.h>
using namespace std;

int power(int n, int index)
{
    //Base Case
    if (index == 0)
    {
        return 1;
    }
    // recusrsive case
    int smallOutput = power(n, index - 1);
    //calculation
    return n * smallOutput;
}

int main()
{
    int n;
    cin >> n;

    int index;
    cin >> index;
    cout << power(n, index);
    return 0;
}