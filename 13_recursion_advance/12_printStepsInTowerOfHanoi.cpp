#include <bits/stdc++.h>
using namespace std;

void printSteps(int n, char source, char helper, char destination)
{
    if (n == 0)
    {
        return;
    }
    printSteps(n - 1, source, destination, helper);
    cout << "Moving disk " << n << "  from " << source << " to " << destination << endl;
    printSteps(n - 1, helper, source, destination);
}

int main()
{
    int noOfDisc = 3;
    printSteps(noOfDisc, 'A', 'H', 'C');
    return 0;
}