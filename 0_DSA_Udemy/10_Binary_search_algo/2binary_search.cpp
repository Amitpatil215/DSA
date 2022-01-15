#include <bits/stdc++.h>
using namespace std;

int binarySearcg(int a[], int n, int key)
{
    int s = 0;
    int e = n - 1;
    int mid;
    while (s <= e)
    {
        // mid = (s + e) / 2; /// it might exceed int max value on adding to int

        mid = s + (e - s) / 2;
        if (a[mid] == key)
        {
            return mid;
        }
        else if (a[mid] < key) // element can be found in right side
        {
            s = mid + 1;
        }
        else if (a[mid] > key) // element can be found in left side
        {
            e = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    int key, foundIndex;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter search key";
    cin >> key;
    sort(a, a + n);
    foundIndex = binarySearcg(a, n, key);
    if (foundIndex > 0)
    {
        cout << "element found at index " << foundIndex;
    }
    else
    {
        cout << "element not found";
    }
    return 0;
}