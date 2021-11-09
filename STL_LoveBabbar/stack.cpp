#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<string> s;
    s.push("Love");
    s.push("Babbar");
    s.push("Kumar");
    cout << s.top() << endl;

    s.pop();
    cout << s.top() << endl;

    cout << s.size() << endl;
}