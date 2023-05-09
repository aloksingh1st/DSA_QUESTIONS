#include <bits/stdc++.h>
using namespace std;

// creation

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

// insert at head of list

void insertAtHead(Node *&head, int data)
{

    // create new node

    Node *newNode = new Node(data);

    newNode->next = head;
    head = newNode;
}

// insert at tail of list

void insertAtTail(Node *&tail, int data)
{

    // create new node

    Node *newNode = new Node(data);

    tail->next = newNode;
    tail = newNode;
}

// insert at given position of the list

void insertAtPosition(Node *&head, Node *&tail, int data, int p)
{

    if (p == 1)
    {
        insertAtHead(head, data);
        return;
    }

    // creating temp node and counter to check where to insert it

    Node *tempNode = head;
    int cnt = 1;

    // traversing and counting counter for finding the position p in the list

    while (cnt < p - 1)
    {
        cnt++;
        tempNode = tempNode->next;
    }
    //checking and updating tail if it's last position of the list
    if(tempNode ->next == NULL){
        insertAtTail(tail, data);
        return;
    }

    // creating a new node and inserting it at position p

    Node *newNode = new Node(data);
    newNode->next = tempNode->next;
    tempNode->next = newNode;



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

int main()
{

    Node *head = new Node(12);
    Node *tail = head;
    insertAtTail(tail, 11);

    printLL(head);

    insertAtPosition(head, tail ,88, 3);
    insertAtPosition(head, tail ,87, 4);



    printLL(head);
    cout<<tail->data << endl;
    return 0;
}