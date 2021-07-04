//* Evaluate postfix expression
//S= O(n)
//T= O(n)
#include <bits/stdc++.h>
using namespace std;

int evaluateReversePolishNotation(vector<string> str)
{
    stack<int> st;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == "+" || str[i] == "-" || str[i] == "*" || str[i] == "/")
        {
            int v1 = st.top();
            st.pop();
            int v2 = st.top();
            st.pop();
            if (str[i] == "+")
            {
                st.push(v1 + v2);
            }
            else if (str[i] == "-")
            {
                st.push(v2 - v1);
            }
            else if (str[i] == "/")
            {
                st.push(v2 / v1);
            }
            else if (str[i] == "*")
            {
                st.push(v2 * v1);
            }
        }
        else
        {
            // operands
            int temp = atoi(str[i].c_str()); //coverting string to c style char array
                                             // using atoi function for converting it to int

            st.push(temp);
        }
    }
    return st.top();
}

int main()
{
    vector<string> str;
    str.push_back("4");
    str.push_back("13");
    str.push_back("5");
    str.push_back("/");
    str.push_back("+");
    cout << evaluateReversePolishNotation(str);
    return 0;
}