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

struct Result {
    Result()
        : output1(){

          };
    int output1[100];
};

Result altTab(int input1, int input2, int input3[]) {
    int loc;
    Result result = Result();
    if (input2 == 0) {
        loc = 0;
        for (int i = 0; i < input1; i++) {
            result.output1[i] = input3[i];
        }
        return result;
    } else {
        loc = (input2 % input1) - 1;
        if (loc == -1) {
            loc = input1-1;
        }
        debug(loc);
        result.output1[0] = input3[loc];
        int k = 1;
        for (int i = 0; i < input1; i++) {
            if (i != loc) {
                result.output1[k] = input3[i];
                k++;
            }
        }
    }
    return result;
}
void solve() {
    int arr[] = {4, 1, 3, 7, 6, 8, 5, 2, 10, 9};
    Result result = altTab(10, 0, arr);
    for (int i = 0; i < 10; i++) {
        cout << result.output1[i] << " ";
    }
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