#include <bits/stdc++.h>
using namespace std;

void reverseAQueue(queue<int> &q)
{
    stack<int> s;
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}
int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    reverseAQueue(q);
    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }

    return 0;
}