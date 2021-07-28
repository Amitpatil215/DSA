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
};
int main()
{

    return 0;
}