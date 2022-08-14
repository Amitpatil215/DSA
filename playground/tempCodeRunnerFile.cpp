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