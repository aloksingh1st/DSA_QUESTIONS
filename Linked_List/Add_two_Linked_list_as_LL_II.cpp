#include <bits/stdc++.h>
using namespace std;

class ListNode
{

public:
    int data;
    ListNode *next;

    ListNode(int data)
    {
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

int printInt(ListNode *&head)
{
    ListNode *newNode = head;
    int toExport = 0;

    while (newNode != NULL)
    {
        // cout << " " << newNode->data << " --> ";
        toExport = toExport * 10 + newNode->data;
        newNode = newNode->next;
    }
    // cout << endl;
    return toExport;
}

void Reverse(ListNode *&head)
{
    ListNode *current = head;
    ListNode *prev = NULL, *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

ListNode *addTwoLists(ListNode *first, ListNode *second)
{

    int a = printInt(first);
    int b = printInt(second);

    int n = a + b;
    ListNode *ans = new ListNode(n % 10);
    n = n / 10;

    while (n != 0)
    {
        // temp = n%10;
        insertAtHead(ans, n % 10);
        n = n / 10;
    }

    return ans;
}

ListNode *intToLl(int v)
{
    int n = v;

    ListNode *ans = new ListNode(n % 10);
    n = n / 10;

    while (n != 0)
    {
        // temp = n%10;
        insertAtHead(ans, n % 10);
        n = n / 10;
    }

    return ans;
}

int main()
{

    ListNode *head = new ListNode(5);
    // insertAtHead(head, 5);

    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    ListNode *head2 = new ListNode(5);
    insertAtHead(head2, 4);
    
    ListNode * head3 = addTwoLists(head, head2);

    printLL(head3);

    return 0;
}