#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        int val = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }

        cout << "Memory is free for node with data " << val << endl;
    }
};

void insertAtHead(Node *&head, int data)
{

    // create new node

    Node *newNode = new Node(data);

    newNode->next = head;
    head = newNode;
}

void printLL(Node *&head)
{
    Node *newNode = head;

    while (newNode != NULL)
    {
        cout << " " << newNode->data << " --> ";
        newNode = newNode->next;
    }
    cout << endl;
}

Node *middleNode(Node *head)
{
    Node *temp = head;

    float len = 0;

    while (temp->next != NULL)
    {
        len++;
        temp = temp->next;
    }

    int n = ceil(len / 2);

    temp = head;
    int cnt = 0;

    while (cnt < n)
    {
        cnt++;
        temp = temp->next;
    }

    return temp;
}

int main()
{

    Node *head = new Node(4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    printLL(head);

    Node *newHead = middleNode(head);

    printLL(newHead);

    return 0;
}