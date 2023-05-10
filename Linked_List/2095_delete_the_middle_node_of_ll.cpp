#include <bits/stdc++.h>
using namespace std;

class Node{
    public:

        int data;
        Node * next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
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


void deleteAtPosition(Node* &head, int p){

    if(p == 1){
        Node * temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    else{
        Node *prev = NULL;
        Node *curr = head;


        int cnt = 1;

        while(cnt < p){
            prev= curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;

        delete curr;
    }
}

Node * deleteMiddle(Node *head){
    Node * temp = head;

    float len = 0;

    while(temp->next != NULL){
        len ++;
        temp = temp->next;
    }

    int n = ceil(len/2);

    deleteAtPosition(head, n+1);
    
    return head;

}

int main(){

    Node* head = new Node(4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    printLL(head);

    Node * newHead = deleteMiddle(head);

    printLL(newHead);

    return 0;
}