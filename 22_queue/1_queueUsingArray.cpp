#include <iostream>
using namespace std;

template <typename T>
class Queue
{
public:
    T *arr;
    int frontIndex;
    int nextIndex;
    int size;
    int capacity;

    Queue()
    {
        arr = new T[5];
        capacity = 5;
        nextIndex = 0;
        size = 0;
        frontIndex = -1;
    }

    Queue(int cap)
    {
        arr = new T[cap];
        capacity = cap;
        nextIndex = 0;
        size = 0;
        frontIndex = -1;
    }

    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return getSize() == 0;
    }

    void push(T element)
    {
        if (getSize() == capacity)
        {
            cout << "Queue is Full" << endl;
            return;
        }
        arr[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        if (frontIndex == -1)
        {
            frontIndex = 0;
        }
        size++;
    }

    T front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        return arr[frontIndex];
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        frontIndex = (frontIndex + 1) % capacity;
        size--;
    }
};

int main()
{
    Queue<int> q;
    q.push(10);
    cout << q.front() << endl;
    cout << q.getSize() << endl;
    q.push(20);
    cout << q.getSize() << endl;
    q.push(30);
    cout << q.getSize() << endl;
    q.push(40);
    cout << q.getSize() << endl;
    q.push(50);
    cout << q.getSize() << endl;
    q.push(60);
    q.push(70);
    cout << q.front() << endl;
    q.pop();
    q.pop();
    q.pop();
    cout << q.front() << endl;
    cout << q.getSize() << endl;
    cout << q.isEmpty() << endl;
    q.push(60);
    q.push(70);
    q.pop();
    q.pop();
    cout << q.front() << endl;
    return 0;
}