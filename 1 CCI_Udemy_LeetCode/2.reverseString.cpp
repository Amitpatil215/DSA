//https://leetcode.com/problems/reverse-string/submissions/
class Solution
{
public:
    void reverseString(vector<char> &str)
    {
        // use two pointer approach
        int s = 0;
        int e = str.size() - 1;

        while (s < e)
        {
            swap(str[s], str[e]);
            s++;
            e--;
        }
    }
};