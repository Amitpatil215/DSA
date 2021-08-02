#include <bits/stdc++.h>
using namespace std;

void removeConsecutiveDuplicates(char arr[])

{
    //base case
    if (arr[0] == '\0')
    {
        return;
    }

    if (arr[0] == arr[1])
    {
        for (int i = 0; arr[i] != '\0'; i++)
        {
            arr[i] = arr[i + 1];
        }
        removeConsecutiveDuplicates(arr);
    }
    else
    {
        removeConsecutiveDuplicates(arr + 1);
    }
}

int main()
{
    char arr[] = "aaabbbcccddd";
    removeConsecutiveDuplicates(arr);
    cout << arr << endl;
    return 0;
}