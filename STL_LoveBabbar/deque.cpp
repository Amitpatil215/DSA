#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> d;

    d.push_back(1);
    d.push_front(2);

    for (int i : d)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Print first index element" << d.at(1) << endl;
    d.erase(d.begin(), d.begin() + 1); // erase first element
}