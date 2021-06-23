#include <bits/stdc++.h>
using namespace std;

void mergeArrays(int arr[], int si, int ei, int mid)
{
    int subArrayOne = mid - si + 1;
    int subArrayTwo = ei - mid;

    // create temp arrays
    int leftArray[subArrayOne];
    int rightArray[subArrayTwo];

    //copy data to temp arrays
    for (int i = 0; i < subArrayOne; i++)
    {
        leftArray[i] = arr[si + i];
    }

    for (int i = 0; i < subArrayTwo; i++)
    {
        rightArray[i] = arr[mid + 1 + i];
    }

    int indexOfSubArrayOne = 0;
    int indexOfSubArrayTwo = 0;
    int indexOfMergedArray = si;

    //merge the temp arrays back into array[left...right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
        {
            arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    /// copy the remaining element of left, if there are any
    while (indexOfSubArrayOne < subArrayOne)
    {
        arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo)
    {
        arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void mergeSort(int arr[], int si, int ei)
{
    if (si >= ei)
    {
        return;
    }

    int mid = si + (ei - si) / 2;
    mergeSort(arr, si, mid);
    mergeSort(arr, mid + 1, ei);

    mergeArrays(arr, si, ei, mid);
}

int main()
{
    int arr[] = {5, 6, 7, 3, 2, 1, 4};
    int n = 7;
    int si = 0;
    int ei = 6;
    mergeSort(arr, si, ei);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}