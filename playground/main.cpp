#include <bits/stdc++.h>
using namespace std;

#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1> void __f(const char *name, Arg1 &&arg1) {
  cout << name << " : " << arg1 << endl;
}

template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args) {
  const char *comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}

void solve() {}

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