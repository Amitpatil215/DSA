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
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}

Node *insertAtIthPosition(int data, Node *head, int index)
{
    if (index <0)
    {
        return head;
    }
    if (index == 0)
    {
        Node *n = new Node(data);
        n->next = head;
        head = n;
        return head;
    }
    // for inserting at ith node we need i-1 jumps
    for (int i = 0; i < index-1 && head; i++)
    {
        head = head->next;
    }
    cout << head->data << endl;
    if (head != NULL)
    {
        Node *n = new Node(data);
        n->next = head->next;
        head->next = n;
        return head;
    }
    return head;
}

int main()
{
    Node *head = takeInput();
    insertAtIthPosition(10, head, 3);
    print(head);
    return 0;
}