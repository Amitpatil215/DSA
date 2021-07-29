#include <bits/stdc++.h>
using namespace std;

void kSmallestElements(int *a, int n, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(a[i]);
    }
    for (int i = k; i < n; i++)
    {
        if (a[i] < pq.top())
        {
            pq.pop();
            pq.push(a[i]);
        }
    }
    //print
    while (!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }
}
int main()
{
    int arr[] = {5, 6, 9, 12, 3, 13, 2};
    kSmallestElements(arr, 7, 3);
    /* 5
       3
       2 */
    return 0;
}