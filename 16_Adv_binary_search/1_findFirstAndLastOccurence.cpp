#include <bits/stdc++.h>
using namespace std;

int getFirst(vector<int> v, int target)
{
    int s = 0;
    int e = v.size() - 1;

    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (v[mid] == target)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (v[mid] < target)
        {
            s = mid + 1;
        }
        else if (v[mid] > target)
        {
            e = mid - 1;
        }
    }
    return ans;
}

int getLast(vector<int> v, int target)
{
    int s = 0;
    int e = v.size() - 1;

    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (v[mid] == target)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (v[mid] < target)
        {
            s = mid + 1;
        }
        else if (v[mid] > target)
        {
            e = mid - 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(4);
    v.push_back(4);
    v.push_back(4);
    v.push_back(4);
    v.push_back(4);
    v.push_back(5);
    v.push_back(8);
    int target = 4;
    cout << getFirst(v, target) << endl;
    cout << getLast(v, target) << endl;
    return 0;
}