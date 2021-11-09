#include <iostream>
#include <map>
using namespace std;

// in map we get complexity ofr O(logn)

int main()
{
    map<int, string> m;
    m[0] = "Zero";
    m[2] = "two";
    m[1] = "one";

    for (auto e : m)
    {
        cout << e.first << " -> " << e.second << endl;
    }
}