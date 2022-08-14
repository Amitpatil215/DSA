/*
Minimum Comparisons to find Second Largest Element
https://iq.opengenus.org/minimum-comparisons-to-find-second-largest-element/#:~:text=In%20short%2C%20the%20Minimum%20Comparisons,10%20%2D%202%20%3D%201032%20comparisons.

In this article, we have demonstrated the mathematical analysis to find out the
minimum number of Comparisons to find the second largest or the second smallest
element. We have presented the algorithm for it as well along with other
algorithms that look efficient but are not.

In short, the Minimum Comparisons to find Second Largest Element or Second
Smallest Element is N + logN - 2 comparisons. Hence, if there are 1024 elements,
then we need at least 1024 + 10 - 2 = 1032 comparisons. Also, note that if we
need to find the Largest or Smallest element, then we need at least ==1024
comparisons. Hence, there is an increase of 8 comparisons only.
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

void solve() {
    vector<int> arr = {61, 6, 100, 9, 10, 12, 17};
    int first_min = *min_element(arr.begin(), arr.end());  // n-1 comparisons
    // it will store all the elements which are compared with first_min
    vector<int> ansVec;

    // everytime we generate new vec array of n/2 elements after comaprison we
    vector<int> copyVec = arr;
    while (copyVec.size() != 1) {
        vector<int> newVec;
        for (int i = 0; i < copyVec.size(); i += 2) {
            int x = copyVec[i];
            if (i + 1 < copyVec.size()) {
                int y = copyVec[i + 1];

                if (x < y) {
                    newVec.push_back(x);
                } else {
                    newVec.push_back(y);
                }
                if (x == first_min) {
                    ansVec.push_back(y);

                } else if (y == first_min) {
                    ansVec.push_back(x);
                }
            } else {
                newVec.push_back(x);
            }
        }
        copyVec = newVec;
    }
    int second_element = *min_element(ansVec.begin(), ansVec.end());
    debug(first_min, second_element);
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