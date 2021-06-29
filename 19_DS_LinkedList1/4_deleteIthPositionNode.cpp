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

Node *deleteIthPositionElement(Node *head, int position)
{
    int index = position - 1;

    if (index < 0)
    {
        return head;
    }
    if (index == 0)
    {
        delete head->next;
        head = NULL;
    }

    for (int i = 0; i < index && head; i++)
    {
        head = head->next;
    }

    if (head)
    {
        Node *nextNode = (head->next)->next;
        delete head->next;
        head->next = nextNode;
    }
    return head;
}

int main()
{
    Node *head = takeInput();
    deleteIthPositionElement(head, 3);
    print(head);
    return 0;
}