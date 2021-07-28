#include <bits/stdc++.h>
using namespace std;

void implaceHeapSort(int *pq, int n)
{
    // build heap in input array
    for (int i = 0; i < n; i++)
    {
        int childIndex = i;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] < pq[parentIndex])
            {
                swap(pq[childIndex], pq[parentIndex]);
                childIndex = parentIndex;
            }
            else
            {
                break;
            }
        }
    }
    int size = n;

    // call remove min function n times
    while (size >= 1)
    {
        swap(pq[0], pq[size - 1]);
        size--;

        int parentIndex = 0;
        while (true)
        {
            int leftChildIndex = 2 * parentIndex + 1;
            int rightChildIndex = 2 * parentIndex + 2;
            int minElmentIndex = parentIndex;
            if (leftChildIndex < size && pq[leftChildIndex] < pq[minElmentIndex])
            {
                minElmentIndex = leftChildIndex;
            }
            if (rightChildIndex < size && pq[rightChildIndex] < pq[minElmentIndex])
            {
                minElmentIndex = rightChildIndex;
            }
            if (minElmentIndex == parentIndex)
                break;
            swap(pq[parentIndex], pq[minElmentIndex]);
            parentIndex = minElmentIndex;
        }
    }
}
int main()
{
    int input[] = {5, 1, 2, 0, 8};
    implaceHeapSort(input, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << input[i] << " ";
    }
    // 8 5 2 1 0
    return 0;
}