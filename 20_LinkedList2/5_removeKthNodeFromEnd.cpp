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

void removeKthElement(Node *head, int k)
{
    Node *one = head;
    Node *two = head;
    while (k--)
    {
        two = two->next;
    }

    while (two->next != NULL)
    {
        two = two->next;
        one = one->next;
    }

    Node *temp = one->next;
    one->next = one->next->next;
    delete temp;
}

int main()
{
    Node *head = takeInput();
    removeKthElement(head, 2);
    print(head);
    return 0;
}