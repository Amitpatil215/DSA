#include <bits/stdc++.h>
using namespace std;

double gsum(int k)
{
    //base case
    if (k == 0)
    {
        return 1;
    }

    // recusrsive case
    double smallAns = gsum(k - 1);

    //calculation
    return smallAns + 1.0 / (pow(2, k));
}

int main()
{
    cout << gsum(3);
    return 0;
}