#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> *vp = new vector<int>(); // dynamic
    vector<int> v;                       // static
    vector<int> v2(10, 3);               // initialize a vector size=10, default vlue=3

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    v[1] = 100;
    v[4] = 1001;
    v[5] = 1234;

    cout << v.at(0) << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;
    cout << v[3] << endl;
    cout << v[4] << endl;
    cout << v[5] << endl;

    // loop on vector
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }

    return 0;
}