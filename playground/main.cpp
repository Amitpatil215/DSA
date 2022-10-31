#include <bits/stdc++.h>
using namespace std;

#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
    cout << name << " : " << arg1 << endl;
}

template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args) {
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}

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

void solve() {
    // long long arr[] = {0, 2, 7, 10, 6, 3, 4, 9, 8, 5};
    long long arr[] = {289837621, 687176338, 941575810, 783231857, 462056296,
                       172999051, 971906113, 684533604, 75682691,  685306490,
                       23633765,  964542384, 343752255, 157473882, 520596748,
                       781207617, 58240683,  604998138, 941111217, 536943549,
                       585033793, 16112334,  146772209, 628477534, 168738081,
                       358041337, 3914733,   663306853, 335392934, 786330443};
    cout << getInversions(arr, 30) << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("E:/Work/Interview Prep/DSA/playground/input.txt", "r", stdin);
    freopen("E:/Work/Interview Prep/DSA/playground/output.txt", "w", stdout);
#endif
    clock_t z = clock();
    int test = 1;
    cin >> test;
    while (test--) {
        solve();
    }
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
    return 0;
}