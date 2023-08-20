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


ListNode * Reverse(ListNode * &head){
    ListNode* current = head;
    ListNode* prev = NULL, *next = NULL;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}


ListNode *lastAppearance(ListNode *head) { 
	// Write your code here.

    head = Reverse(head); 
  unordered_map<int, int> m;

  ListNode *temp = head;
  ListNode *p = head;

  while (temp != NULL) {
    if (m[temp->data] == 1) {
      p->next = temp->next;
    } else {
      m[temp->data] = 1;
      p = temp;
    }
    temp = temp->next;
  }
  
  head = Reverse(head);
  return head;
}


int main(){

    ListNode * head = new ListNode(7);
    // insertAtHead(head, 7);
    insertAtHead(head, 11);
    insertAtHead(head, 13);
    insertAtHead(head, 23);
    insertAtHead(head, 7);
    insertAtHead(head, 11);
    insertAtHead(head, 13);


    // LastNode(head)->data<<"--------------------------------"<<endl;

    ListNode *newHead = lastAppearance(head);

    printLL(newHead);



    return 0;
}