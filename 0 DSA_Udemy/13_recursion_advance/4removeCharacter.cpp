#include <bits/stdc++.h>
using namespace std;

void removeA(char arr[])
{
    //base case
    if (arr[0] == '\0')
    {
        return;
    }

    if (arr[0] == 'a')
    {

        for (int i = 0; arr[i] != '\0'; i++)
        {
            arr[i] = arr[i + 1];
        }

        removeA(arr);
    }
    else
    {
        removeA(arr + 1);
    }
}

int main()
{
    char arr[] = "Hello amit Patil";
    removeA(arr);
    for (int i = 0; arr[i] != '\0'; i++)
    {
        cout << arr[i];
    }
    return 0;
}