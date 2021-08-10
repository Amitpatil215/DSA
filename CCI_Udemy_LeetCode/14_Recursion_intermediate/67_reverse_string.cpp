class Solution
{
public:
    void reverse(string &s, int begin, int end)
    {
        while (begin <= end)
        {
            swap(s[begin], s[end]);
            begin++;
            end--;
        }
    }

    string reverseWords(string s)
    {
        int n = s.size();
        // reverse words
        int begin = 0;
        int end = 0; // it traverses throw the whole sentence
        while (end < n)
        {
            if (s[end] == '')
            {
                reverse(s, begin, end - 1);
                end++;
                begin = end;
            }
            else
            {
                end++;
            }
        }
        // reverse last word
        reverse(s, begin, end - 1);

        // reverse complete string
        reverse(s, 0, n - 1);

        // remove multiple spaces
        string ans;
        int i = 0;

        // remove starting spaces
        while (s[i] == ' ')
        {
            i++;
        }

        while (i < n)
        {
            // only consider first space
            if (s[i] == ' ')
            {
                ans.push_back(' ');
                i++;
            }
            // if more than one space present move ahead
            while (s[i] == ' ')
            {
                i++;
            }
        }

        // remove trailing spaces
        if (ans.back() == ' ')
        {
            ans.pop_back();
        }

        return ans;
    }
};