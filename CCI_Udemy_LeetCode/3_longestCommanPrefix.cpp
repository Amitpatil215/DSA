//https://leetcode.com/problems/longest-common-prefix/submissions/
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string ans = "";

        if (strs.size() == 0)
            return ans;
        // will give min length string from vector
        string s = *min_element(strs.begin(), strs.end());

        // iterate over each character of min string
        for (int i = 0; i < s.size(); i++)
        {
            // check for ith character of every string in vector
            // if found mismatch return
            for (int j = 0; j < strs.size(); j++)
            {
                if (s[i] != strs[j][i])
                {
                    return ans;
                }
            }
            // else append ith char in ans
            ans.push_back(s[i]);
        }
        return ans;
    }
};