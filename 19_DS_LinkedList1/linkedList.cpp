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

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}

/// inserting at head
Node *takeInput()
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

/// inserting at tail
Node *takeInputFromTail()
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
            n->next = head;
            head = n;
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

int length(Node *head)
{
    int len = 0;
    while (head) //while head exist similar to when head!=NULL
    {
        len++;
        head = head->next;
    }
    return len;
}

int main()
{
    //* dynamically
    /*
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    n3->next = n4;
    return 0;
    */

    // statically
    Node N1(1);
    Node N2(2);
    Node N3(3);
    Node N4(4);
    Node N5(5);

    Node *head = &N1;
    N1.next = &N2;
    N2.next = &N3;
    N3.next = &N4;
    N4.next = &N5;

    print(head);
    cout << endl;
    // print(takeInput()); //take input from head
    // print(takeInputFromTail()); //take input from tail

    cout << length(takeInputFromTail());
}