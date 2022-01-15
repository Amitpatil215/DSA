#include <bits/stdc++.h>
using namespace std;

int noOfWays(int n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return noOfWays(n - 1) + noOfWays(n - 2) + noOfWays(n - 3);
}
int main()
{
    cout << noOfWays(4) << endl;
    cout << noOfWays(3) << endl;
    cout << noOfWays(10);

    return 0;
}