#include <bits/stdc++.h>
using namespace std;
bool isBalancedParanthesis(string str)
{
    stack<char> s;
    for (int i = 0; i < str.size(); i++)
    {
        char temp = str[i];
        if (temp == '(' || temp == '[' || temp == '{')
        {
            s.push(temp);
        }
        else
        {
            if (s.empty()) // we can only perform s.top() operations if stack is not empty
                return false;
            else if (temp == ')' && s.top() == '(')
            {
                s.pop();
            }
            else if (temp == ']' && s.top() == '[')
            {
                s.pop();
            }
            else if (temp == '}' && s.top() == '{')
            {
                s.pop();
            }
        }
    }
    return s.empty();
}
int main()
{
    string str = "()";
    cout << isBalancedParanthesis(str);
    return 0;
}