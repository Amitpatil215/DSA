

#include <bits/stdc++.h>
using namespace std;

// T=O(n)
// S=O(n)
string removeAllAdjecentDuplicateChar(string str)
{
    stack<char> st;
    for (int i = 0; i < str.size(); i++)
    {
        if (st.empty() || str[i] != st.top())
        {
            st.push(str[i]);
        }
        else
        {
            st.pop();
        }
    }
    string ans = "";
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// T=O(n)
// S=O(1)
string removeAllAdjecentDuplicateCharBySimulatingStack(string str)
{
    int stptr = -1;
    for (int i = 0; i < str.size(); i++)
    {
        if (stptr == -1 || str[i] != str[stptr])
        {
            stptr++;
            str[stptr] = str[i];
        }
        else
        {
            stptr--;
        }
    }
    string ans = "";
    for (int i = 0; i <= stptr; i++)
    {
        ans.push_back(str[i]);
    }
    return ans;
}

int main()
{
    string str = "abbaca";
    cout << removeAllAdjecentDuplicateChar(str) << endl;
    cout << removeAllAdjecentDuplicateCharBySimulatingStack(str) << endl;
    return 0;
}