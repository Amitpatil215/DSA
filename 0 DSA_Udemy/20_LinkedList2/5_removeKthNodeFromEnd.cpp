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

Node *removeKthElement(Node *head, int k)
{
    Node *copyHead = head;
    Node *one = head;
    Node *two = head;
    while (k--)
    {
        two = two->next;
    }

    if (two == NULL) //when length of LL == K
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    else
    {

        while (two->next != NULL)
        {
            two = two->next;
            one = one->next;
        }

        Node *temp = one->next;
        one->next = one->next->next;
        delete temp;
        return copyHead;
    }
}

int main()
{
    Node *head = takeInput();
    print(removeKthElement(head, 2));

    return 0;
}