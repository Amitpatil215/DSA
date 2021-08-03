class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;

        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/" || tokens[i] == "*")
            {
                int firstElement = st.top();
                st.pop();
                int secondElement = st.top();
                st.pop();
                int result = 0;
                if (tokens[i] == "+")
                {
                    result = firstElement + secondElement;
                }
                else if (tokens[i] == "-")
                {
                    result = secondElement - firstElement;
                }
                else if (tokens[i] == "*")
                {
                    result = firstElement * secondElement;
                }
                else if (tokens[i] == "/")
                {
                    result = secondElement / firstElement;
                }
                st.push(result);
            }
            else
            {
                st.push(atoi(tokens[i].c_str()));
            }
        }
        return st.top();
    }
};