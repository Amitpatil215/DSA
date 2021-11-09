#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{

    vector<int> v;

    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);

    cout << binary_search(v.begin(), v.end(), 6) << endl; // find 6 i=using binary search

}