#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> a(5,-1);



    vector<int> v;
    cout << v.capacity() << endl;

    v.push_back(1);
    cout << v.capacity() << endl;

    v.push_back(2);
    cout << v.capacity() << endl;

    v.push_back(3);
    cout << v.capacity() << endl;
    cout << v.at(1) << endl;
    cout << v.front() << endl;
    cout << v.back() << endl;

    for (int i : v)
    {
        cout << i << ' ';
    }
    cout << endl;

    v.pop_back();

    for (int i : v)
    {
        cout << i << ' ';
    }

    cout << endl;
}