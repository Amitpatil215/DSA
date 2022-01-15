#include <bits/stdc++.h>
using namespace std;

int waysToReach(int steps)
{
    if (steps < 0)
    {
        return 0;
    }

    if (steps == 1 || steps == 0)
    {
        return 1;
    }

    return waysToReach(steps - 1) + waysToReach(steps - 2) + waysToReach(steps - 3);
}

int main()
{
    int steps = 4;
    cout << waysToReach(steps);
    return 0;
}