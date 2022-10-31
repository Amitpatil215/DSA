/*
https://www.codingninjas.com/codestudio/problems/count-inversions_615

For a given integer array/list 'ARR' of size 'N' containing all distinct values,
find the total number of 'Inversions' that may exist. An inversion is defined
for a pair of integers in the array/list when the following two conditions are
met. A pair ('ARR[i]', 'ARR[j]') is said to be an inversion when:

1. 'ARR[i] > 'ARR[j]'
2. 'i' < 'j'

Where 'i' and 'j' denote the indices ranging from [0, 'N').
Sample Input 1 :
3
3 2 1
Sample Output 1 :
3
Explanation of Sample Output 1:
We have a total of 3 pairs which satisfy the condition of inversion. (3, 2), (2,
1) and (3, 1). Sample Input 2 :
5
2 5 1 3 4
Sample Output 2 :
4
Explanation of Sample Output 1:
We have a total of 4 pairs which satisfy the condition of inversion. (2, 1), (5,
1), (5, 3) and (5, 4).

 */
#include <bits/stdc++.h>
using namespace std;
void merge(long long *arr, int start, int mid, int end, long long &count) {
    int n1 = mid - start + 1;
    int n2 = end - mid;
    long long L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[start + i];
    }

    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }

    int k = start, i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];

            i++;
            k++;
        } else {
            count += n1 - i;
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void divide(long long *arr, int start, int end, long long &count) {
    if (start >= end) return;
    int mid = (end - start) / 2 + start;

    divide(arr, start, mid, count);
    divide(arr, mid + 1, end, count);
    merge(arr, start, mid, end, count);
}
long long getInversions(long long *arr, int n) {
    // Write your code here.
    long long count = 0;
    divide(arr, 0, n - 1, count);
    return count;
}