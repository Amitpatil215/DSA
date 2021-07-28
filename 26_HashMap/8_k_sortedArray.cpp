#include <bits/stdc++.h>
using namespace std;

void kSortedArray(int *input, int n, int k)
{
    priority_queue<int> pq;

    for (int i = 0; i < k; i++)
    {
        pq.push(input[i]);
    }

    int start = 0;
    for (int i = k; i < n; i++)
    {
        input[start] = pq.top();
        pq.pop();
        start++;
        pq.push(input[i]);
    }
    while (!pq.empty())
    {
        input[start] = pq.top();
        pq.pop();
        start++;
    }
}
int main()
{
    int input[] = {10, 12, 6, 7, 9};
    int k = 3;
    kSortedArray(input, 5, k);
    for (int i = 0; i < 5; i++)
    {
        cout << input[i] << " ";
    }
    /* 12 10 9 7 6  */
}