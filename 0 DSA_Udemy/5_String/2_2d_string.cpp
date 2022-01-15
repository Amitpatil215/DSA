#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> v;
    v.push_back("s");
    v.push_back("hello");

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i]<<endl;
        // We are sorting 2D array
        sort(v[i].begin(), v[i].end());
        cout << v[i]<<endl;
    }
    return 0;
}