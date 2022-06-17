#include <bits/stdc++.h>
using namespace std;

array<int, 3> arr; // {0,0,0}
int main()
{
    array<int, 3> arr;              // {?,?,?}
    array<int, 5> arr1 = {3, 2, 1}; // {3,2,1,0,0}
    array<int, 3> arr2 = {0};       // {0,0,0}
    array<int, 3> arr3;
    arr.fill(10); // {10,10,10}
    arr.at(2);    // give element at index 2

    // * Iterators
    //  begin(), end(), rbegin(), rend()
    array<int, 4> arr4 = {1, 2, 3, 4};
    for (auto it = arr4.begin(); it != arr4.end(); it++)
    {
        cout << *it << endl;
    }
    return 0;
}