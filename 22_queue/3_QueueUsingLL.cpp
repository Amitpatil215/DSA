#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class queue
{
public:
    Node<T> *head;
    Node<T> *tail;
    int size;

    queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return getSize() == 0;
    }
    void push(T data)
    {

        Node<T> *n = new Node<T>(data);
        if (head == NULL)
        {
            cout << "head set" << endl;

            head = n;
            tail = n;
        }
        else
        {

            tail->next = n;
            tail = n;
        }
        size++;
    }

    T front()
    {

        if (isEmpty())
        {
            return 0;
        }
        return head->data;
    }

    void pop()
    {

        if (isEmpty())
        {
            return;
        }

        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
    }
};

int main()
{
    queue<int> q;
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
    cout << q.getSize() << endl;
    q.push(70);
    cout << q.getSize() << endl;
    cout << q.front() << endl;
    q.pop();
    q.pop();
    q.pop();
    cout << q.front() << endl;
    cout << q.getSize() << endl;
    cout << q.isEmpty() << endl;
    return 0;
}