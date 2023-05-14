#include <bits/stdc++.h>
using namespace std;

class Node {

    public:
    int data;
    Node * next;

    Node(int data){
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



void Reverse(Node * &head, int len){
    int cnt = 1;
    Node* current = head;
    Node* prev = NULL, *next = head->next;

    while(current != NULL && cnt < len){
       swap(current->data, next->data);
       current = next;
       next = next->next;
       cnt++;
    }
}


Node *getListAfterReverseOperation(Node *head, int n, int b[]){
    
	// Write your code here.
    stack<int>s;

    Node* ptr=head;

    Node* dummy=new Node(-1);

    Node* temp=dummy;

    for(int i=0;i<n;i++)

    {

        while(b[i]!=0 && ptr!=NULL)

        {

           s.push(ptr->data);

           ptr=ptr->next;

           b[i]--;

        }

        while(!s.empty())

        {

           Node* x=new Node(s.top());

           s.pop();

           temp->next=x;

           temp=temp->next;

        }

    }

    while(ptr!=NULL)

    {

        temp->next=ptr;

        ptr=ptr->next;

        temp=temp->next;

    }

    return dummy->next;
}


int main(){

    Node * head = new Node(10);
    insertAtHead(head, 11);
    insertAtHead(head, 12);
    insertAtHead(head, 13);
    insertAtHead(head, 14);
    insertAtHead(head, 15);


    // LastNode(head)->data<<"--------------------------------"<<endl;

    printLL(head);

    Reverse(head, 3);


    printLL(head);



    return 0;
}