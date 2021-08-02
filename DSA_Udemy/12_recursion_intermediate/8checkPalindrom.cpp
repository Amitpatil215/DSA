#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int a[], int si, int ei)
{
    //base case
    if (si > ei)
    {
        return true;
    }

    if (a[si] == a[ei])
    {
        return isPalindrome(a, si + 1, ei - 1);
    }
    else
    {
        return false;
    }
}

int main()
{
    int a[] = {1, 2, 3, 2, 1};
    cout << isPalindrome(a, 0, 4);
    return 0;
}