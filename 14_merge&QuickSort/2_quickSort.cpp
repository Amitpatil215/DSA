#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int s, int e)
{
    int count = 0;
    int pivot = arr[e];
    int i = s;
    for (int j = s; j < e; j++)
    {
        if (arr[j] < pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[e]);
    return i;
}

void quickSort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int p = partition(arr, s, e);
    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

int main()
{
    int arr[] = {3, 2, 5, 4, 9, 5, 2, 1};
    quickSort(arr, 0, 7);
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}