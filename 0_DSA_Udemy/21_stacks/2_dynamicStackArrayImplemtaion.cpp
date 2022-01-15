#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    int *arr;
    int nextIndex;
    int capacity;

public:
    Stack()
    {
        capacity = 4;
        arr = new int[4];
        nextIndex = 0;
    }

    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        return nextIndex == 0;
    }
    void push(int val)
    {
        if (nextIndex == capacity)
        {

            int *newArray = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newArray[i] = arr[i];
            }
            capacity = capacity * 2;
            delete[] arr;
            arr = newArray;
        }

        arr[nextIndex] = val;
        nextIndex++;
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }

        nextIndex--;
    }
    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[nextIndex - 1];
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << s.top() << endl;
    return 0;
}