#include <bits/stdc++.h>
using namespace std;

int length(char arr[])
{
    //base case
    if (arr[0] == '\0')
    {
        return 0;
    }

    return length(arr + 1) + 1;
}

int main()
{
    char arr[] = "Amit";
    cout << length(arr);

    return 0;
}