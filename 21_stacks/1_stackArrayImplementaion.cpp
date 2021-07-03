#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    int *arr ;
    int nextIndex;
    int capacity;

public:
    Stack()
    {
        capacity = 10;
        arr = new int[10];
        nextIndex = 0;
    }
    Stack(int size)
    {
        capacity = size;
        arr = new int[size];
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
            cout << "Stack is full" << endl;
            return;
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
        return arr[nextIndex-1];
    }
};

int main()
{
    Stack s(4);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout<<s.top()<<endl;
    s.pop();
    cout << s.top() << endl;
    cout<<s.isEmpty()<<endl;
    cout << s.size() << endl;

    return 0;
}