#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<string> q;
    q.push("Love");
    q.push("babbar");

    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
}