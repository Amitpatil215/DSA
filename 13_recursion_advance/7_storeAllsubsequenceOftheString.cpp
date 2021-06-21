#include <bits/stdc++.h>
using namespace std;

void printSubsequence(string input, string output, vector<string> &v)
{
    if (input.length() == 0)
    {
        v.push_back(output);
        return;
    }

    // exclude choice
    printSubsequence(input.substr(1), output, v);

    // include choice
    printSubsequence(input.substr(1), output + input[0], v);
}

int main()
{
    string input;
    cin >> input;
    string output = "";
    vector<string> v;
    printSubsequence(input, output, v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i]<<endl;
    }
    return 0;
}