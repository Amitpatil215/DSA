#include <bits/stdc++.h>
using namespace std;

void printSubsequence(string input, string output)
{
    if (input.length() == 0)
    {
        cout << output << endl;
        return;
    }

    // exclude choice
    printSubsequence(input.substr(1), output);

    // include choice
    printSubsequence(input.substr(1), output + input[0]);
}

void printSubsequenceUsingCharArray(char input[], char output[], int i)
{
    if (input[0] == '\0')
    {
        output[i] = '\0';
        cout << output << endl;
        return;
    }

    // exclude choice
    printSubsequenceUsingCharArray(input + 1, output, i);

    output[i] = input[0];
    // include choice
    printSubsequenceUsingCharArray(input + 1, output, i + 1);
}

int main()
{
    string input;
    cin >> input;
    string output = "";
    printSubsequence(input, output);
    cout << endl;
    cout << "below char array";
    cout << endl;
    char inputArr[] = "abc";
    char outputArr[10];
    printSubsequenceUsingCharArray(inputArr, outputArr, 0);
    return 0;
}