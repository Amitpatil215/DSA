#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

/// inserting at head
Node *takeInput() /// O(n)
{
    int data;
    Node *head = NULL;
    Node *tail = NULL;
    cin >> data;
    while (data != -1)
    {
        Node *n = new Node(data);
        // we have alredy some nodes in linked list
        if (head != NULL)
        {
            tail->next = n;
            tail = tail->next;
        }
        else
        {
            head = n;
            tail = n;
        }
        cin >> data;
    }
    return head;
}

void printIthNode(Node *head, int index) // O(index) index of element which we want to print data
{
    for (int i = 0; i < index && head; i++)
    {
        head = head->next;
    }
    if (head == NULL)
        cout << -1;
    cout << head->data;
}

int main()
{
    Node *head = takeInput();
    printIthNode(head, 3);
    return 0;
}