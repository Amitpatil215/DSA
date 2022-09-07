/*
Make all array elements equal by replacing adjacent pairs by their sum

Given an array arr[] consisting of N integers, the task is to replace a minimum
number of pairs of adjacent elements by their sum to make all array elements
equal. Print the minimum number of such operations required.

Examples:

Input: arr[] = {1, 2, 3}
Output: 1
Explanation: Replace arr[0] and arr[1] by their sum. Therefore, the array
modifies to {3, 3}. After completing the above operations, all the array
elements become equal. Therefore, the number of operations required is 1.

Input: arr[] = {4, 4, 4}
Output: 0

Input
3
3
1 2 3
2
4 4
6
2 1 3 3 1 2

Output:
length of final array 2
no of operations req 1

length of final array 2
no of operations req 0

length of final array 4
no of operations req 2



 */

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

bool isPossibleToDivide(int targetSum, vector<int> &v) {
    int tempSum = 0;
    for (auto a : v) {
        tempSum += a;
        if (tempSum == targetSum) {
            tempSum = 0;
        } else if (tempSum > targetSum) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    int arraySum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        arraySum += v[i];
    }

    // we can devide array to at max n parts
    // check is it possible to divide i no of segments with equal sum
    // if possible then go in array and check does that sum actaull possible or
    // not

    // maxLength possible for now is 1 as we can combine all elements and get
    // one elemnt at the ends
    int maxLength = 1;
    for (int i = 1; i <= n; i++) {
        if (arraySum % i == 0 && isPossibleToDivide(arraySum / i, v)) {
            maxLength = i;
        }
    }

    cout << "length of final array " << maxLength << endl;
    cout << "no of operations req " << n - maxLength << endl;
    cout << endl;
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