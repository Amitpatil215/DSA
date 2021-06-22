#include <bits/stdc++.h>
using namespace std;

int stepsRequired(int n)
{
    if (n == 0)
    {
        return 0;
    }

    return stepsRequired(n - 1) + 1 + stepsRequired(n - 1);
}

int main()
{
    int noOfDisc = 4;
    cout << stepsRequired(noOfDisc);
    return 0;
}