#include <bits/stdc++.h>
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
        next = NULL;
    }
};

template <typename T>
class Stack
{
    Node<T> *head;
    int size;

public:
    Stack()
    {
        head = NULL;
        size = 0;
    }

    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void push(T data)
    {
        Node<T> *n = new Node<T>(data);
        n->next = head;
        head = n;
        size++;
    }
    void pop()
    {
        if (head == NULL)
        {
            cout << "stack is empty" << endl;
            return;
        }
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    T top()
    {
        if (head == NULL)
        {
            cout << "stack is empty" << endl;
            return 0;
        }
        return head->data;
    }
};

int main()
{
    Stack<char> s;
    s.push('a');
    s.push('b');
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << s.getSize() << endl;
    cout << s.isEmpty() << endl;
    return 0;
}