#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string, int> mapa;
    mapa["a"] = 1;
    mapa["b"] = 2;
    mapa["c"] = 3;
    mapa["d"] = 4;
    mapa["e"] = 5;
    mapa["f"] = 6;

    for (unordered_map<string, int>::iterator it = mapa.begin(); it != mapa.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    /*
    f 6
    e 5a 1d 4
    b 2
    c 3
     */

    cout << endl;
    map<string, int> map1;
    map1["a"] = 1;
    map1["b"] = 10;
    map1["c"] = 3;
    map1["f"] = 4;
    map1["e"] = 5;
    map1["d"] = 6;

    for (map<string, int>::iterator it = map1.begin(); it != map1.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}