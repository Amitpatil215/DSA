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

int length(Node *head)
{
    //base case
    if (head == NULL)
    {
        return 0;
    }

    //recursive case
    int smallLength = length(head->next);
    return 1 + smallLength;
}

int main()
{
    Node *head = takeInput();

    cout << length(head);
    return 0;
}