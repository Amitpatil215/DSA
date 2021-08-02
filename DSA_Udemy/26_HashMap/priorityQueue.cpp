#include <bits/stdc++.h>
using namespace std;

class PriorityQueue
{
    vector<int> pq;

public:
    PriorityQueue() {}

    bool isEmpty()
    {
        return pq.size() == 0;
    }

    int getSize()
    {
        return pq.size();
    }

    int getMin()
    {
        if (!isEmpty())
        {
            return pq[0];
        }
        return 0;
    }
    void insert(int element)
    {
        pq.push_back(element);

        // Check for min heap properties
        int childIndex = pq.size() - 1;
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
    int removeMin()
    {
        if (isEmpty())
            return 0;

        int lastElementIndex = pq.size() - 1;
        int removedElement = pq[0];
        swap(pq[0], pq[lastElementIndex]);
        pq.pop_back();

        //check for min Heap properties
        int parentIndex = 0;
        while (true)
        {
            int leftChildIndex = 2 * parentIndex + 1;
            int rightChildIndex = 2 * parentIndex + 2;
            int minElmentIndex = parentIndex;
            if (leftChildIndex < pq.size() && pq[leftChildIndex] < pq[minElmentIndex])
            {
                minElmentIndex = leftChildIndex;
            }
            if (rightChildIndex < pq.size() && pq[rightChildIndex] < pq[minElmentIndex])
            {
                minElmentIndex = rightChildIndex;
            }
            if (minElmentIndex == parentIndex)
                break;
            swap(pq[parentIndex], pq[minElmentIndex]);
            parentIndex = minElmentIndex;
        }
        return removedElement;
    }
};
int main()
{
    PriorityQueue pq;
    pq.insert(100);
    pq.insert(10);
    pq.insert(15);
    pq.insert(4);
    pq.insert(17);
    pq.insert(21);
    pq.insert(67);
    cout << pq.getSize() << endl;
    cout << pq.getMin() << endl;
    while (!pq.isEmpty())
    {
        cout << pq.removeMin() << endl;
    }
    /* 7
       4
       4
       10
       15
       1721
       67
       100
       */
    return 0;
}