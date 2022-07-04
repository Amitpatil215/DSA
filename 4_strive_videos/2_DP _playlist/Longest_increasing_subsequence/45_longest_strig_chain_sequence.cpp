/*
Longest String Chain

venice 41

You are given an array ‘ARR’ of strings, where each string consists of English
lowercase letters. Let’s say a string ‘A’ is a predecessor of string ‘B’ if and
only if we can add exactly one letter anywhere in ‘A’ to make it equal to ‘B’.
For example “abd” is a predecessor of “abcd”, we can add “c” in “abd” to make a
string “abcd” A string chain is a sequence of strings where for every ‘i’ in [1
. . . (K - 1)], ‘Si’ is the predecessor of ‘Si+1’. And the length of such a
string chain is ‘K’. Now your task is to find the length of the longest possible
string chain.

For Example : Let ‘ARR’ = ["x", “xx”, “y”, “xyx”] The longest
possible string chain is “x” -> “xx” -> “xyx” The length of the given chain is
3, hence the answer is 3.

Constraints :
1 ≤ T ≤ 10
1 ≤ N ≤ 300
1 ≤ WORDS[i].length ≤ 16

Time limit: 1 sec
Sample Input 1 :
2
4
x xx y xyx
3
m nm mmm

? Sample Output 1 :
3
2
Explanation For Sample Input 1 :
For test case 1 :
We will print 3 because:
The longest possible string chain is “x” -> “xx” -> “xyx”.
The length of the given chain is 3, hence the answer is 3.

For test case 2 :
We will print 2 because:
The longest possible string chain is “m” -> “nm”.
The length of the given chain is 2, hence the answer is 2.

? Sample Input 2 :
2
5
a bc ad adc bcd
1
m
Sample Output 2 :
3
1

Explanation For Sample Input 2 :
For test case 1 :
We will print 3 because:
The longest possible string chain is “a” -> “ad” -> “adc”.
The length of the given chain is 3, hence the answer is 3.

For test case 2 :
We will print 1 because:
The longest possible string chain is “m”.
The length of the given chain is 1, hence the answer is 1.
 */
static bool cmp(string &s1, string &s2) { return s1.size() < s2.size(); }

bool checkCanBeAddedToChain(string s1, string s2) {
    if (s1.size() != s2.size() + 1) return false;

    int first = 0;   // pointer for string 1
    int second = 0;  // pointer for string 2

    // as s1 will be always be grater than s2
    // loop till it ends
    while (first < s1.size()) {
        if (second < s2.size() && s1[first] == s2[second]) {
            first++;
            second++;
        } else {
            // that means we got a char which is extra than the prev one
            // only move pointer of first string;
            first++;
        }
    }

    // both pointers must end at the end of string
    if (first == s1.size() && second == s2.size()) return true;
    return false;
}
int longestStrChain(vector<string> &words) {
    sort(words.begin(), words.end(), cmp);
    int n = words.size();

    vector<int> dp(n, 1);

    int maxLength = 1;

    for (int index = 0; index < n; index++) {
        for (int earlierIndex = 0; earlierIndex <= index - 1; earlierIndex++) {
            if (1 + dp[earlierIndex] > dp[index] &&
                checkCanBeAddedToChain(words[index], words[earlierIndex])) {
                dp[index] = 1 + dp[earlierIndex];
            }
        }
        if (dp[index] > maxLength) {
            maxLength = dp[index];
        }
    }
    return maxLength;
}
