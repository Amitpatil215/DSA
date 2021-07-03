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
        finalHead->next = mergeTwoList(LH1->next, LH2);
    }
    else
    {
        finalHead = LH2;
        finalHead->next = mergeTwoList(LH1, LH2->next);
    }
    return finalHead;
}

Node *mergeSortLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // break list in two
    Node *slow = head;
    Node *fast = head->next;

    while (fast && fast->next)
    {

        slow = slow->next;
        fast = fast->next->next;
    }
    Node *LLLeft = head;
    Node *LLRight = slow->next;
    slow->next = NULL;

    Node *sortedLeftLL = mergeSortLL(LLLeft);
    Node *sortedRightLL = mergeSortLL(LLRight);

    head = mergeTwoList(sortedLeftLL, sortedRightLL);
    return head;
}
int main()
{
    Node *LH = takeInput();

    print(mergeSortLL(LH));

    return 0;
}