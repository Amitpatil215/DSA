#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string, int> mymap;
    pair<string, int> p("abc", 1);
    mymap.insert(p);

    mymap["def"] = 2;

    cout << mymap["abc"] << endl;
    cout << mymap["def"] << endl;
    cout << mymap.at("abc") << endl;
    cout << mymap.count("abc") << endl;

    cout << mymap.size() << endl;
    mymap.erase("abc");
    return 0;
}