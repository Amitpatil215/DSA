#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> *vp = new vector<int>(); // dynamic
    vector<int> v;                       // static
    vector<int> vz(20, -2);              // initialized 20 sized vector with -2;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v[1] = 100;
    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;
    cout << endl;

    v.pop_back();
    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << endl;
    }

    return 0;
}