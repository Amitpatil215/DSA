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

Node *mergeTwoList(Node *LH1, Node *LH2)
{

    if (LH1 == NULL)
        return LH2;

    if (LH2 == NULL)
        return LH1;

    Node *finalHead = NULL;
    if (LH1->data < LH2->data)
    {
        finalHead = LH1;
        LH1 = LH1->next;
    }
    else
    {
        finalHead = LH2;
        LH2 = LH2->next;
    }

    Node *currHead = finalHead;
    while (LH1 && LH2)
    {
        if (LH1->data < LH2->data)
        {
            currHead->next = LH1;
            LH1 = LH1->next;
        }
        else
        {
            currHead->next = LH2;
            LH2 = LH2->next;
        }
        currHead = currHead->next;
    }
    LH1 != NULL ? currHead->next = LH1 : currHead->next = LH2;
    return finalHead;
}


int main()
{
    Node *LH1 = takeInput();
    Node *LH2 = takeInput();
    print(mergeTwoList(LH1, LH2));

    return 0;
}