#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> removeDuplicates(int arr[], int size)
{
    unordered_map<int, bool> map;
    vector<int> ans;
    for (int i = 0; i < size; i++)
    {
        if (!map.count(arr[i]))
        {
            map[arr[i]] = true;
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

int main()
{
    int arr[] = {1, 25, 2, 3, 1, 2, 5, 6, 3, 9};
    vector<int> ans = removeDuplicates(arr, 10);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}