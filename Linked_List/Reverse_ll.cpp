#include <bits/stdc++.h>
using namespace std;

class ListNode {

    public:
    int data;
    ListNode * next;

    ListNode(int data){
        this->data = data;
        this->next = NULL;
    }

    ~ListNode()
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

void insertAtHead(ListNode *&head, int data)
{

    // create new node

    ListNode *newNode = new ListNode(data);

    newNode->next = head;
    head = newNode;
}


void printLL(ListNode *&head)
{
    ListNode *newNode = head;

    while (newNode != NULL)
    {
        cout << " " << newNode->data << " --> ";
        newNode = newNode->next;
    }
    cout << endl;
}


void Reverse(ListNode * &head){
    ListNode* current = head;
    ListNode* prev = NULL, *next = NULL;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}


int main(){

    ListNode * head = new ListNode(10);
    insertAtHead(head, 11);
    insertAtHead(head, 12);
    insertAtHead(head, 13);
    insertAtHead(head, 14);
    insertAtHead(head, 15);


    // LastNode(head)->data<<"--------------------------------"<<endl;

    printLL(head);

    Reverse(head);

    printLL(head);



    return 0;
}