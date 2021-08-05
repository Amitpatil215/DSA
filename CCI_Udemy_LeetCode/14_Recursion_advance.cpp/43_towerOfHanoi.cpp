#include <bits/stdc++.h>
using namespace std;

void steps(int n, char source, char destination)
{
    if (n <= 0)
    {
        return;
    }

    steps(n - 1, 'S', 'H');
    cout << "Moving disc " << n << " " << source << " -> " << destination << endl;
    steps(n - 1, 'H', 'D');
}
int main()
{

    steps(2, 'S', 'D');
    return 0;
}