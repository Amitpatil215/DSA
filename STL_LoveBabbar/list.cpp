#include <iostream>
#include <list> // implemented linked list using dubly linked list
using namespace std;

int main()
{
    list<int> l;
    l.push_back(1);
    l.push_front(2);

    for (int i : l)
    {
        cout << i << " ";
    }

    cout << endl
         << "After erase" << endl;
    l.erase(l.begin()); // erase takes pointer and deletes the element the pointer pointing at

    for (int i : l)
    {
        cout << i << " ";
    }

    // create list of 5 elements with default value of -3
    list<int> li(5, -3);

    // copy above list in a new list
    list<int> n(li);
}