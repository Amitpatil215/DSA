#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> s;
    s.insert(5);
    s.insert(5);
    s.insert(1);
    s.insert(6);
    s.insert(6);
    s.insert(2);

    for (int i : s)
    {
        cout << i << " ";
    }

    cout << endl;
    cout << s.count(5) << endl; // find no of times 5 ocuured, usually used to find no is present or not

    set<int>::iterator it = s.find(5);
    cout << *it << endl;

    // unordered set
    // Doesnt stores or returns in asceding order of value
}