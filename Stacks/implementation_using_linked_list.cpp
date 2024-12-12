#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Stack
{
    Node *head;

public:
    Stack()
    {
        head = NULL;
    }

    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
    bool isFull();
};

bool Stack::push(int x)
{
    if (isFull())
    {
        cout << "Stack Overflow" << endl;
        return false;
    }
    Node *temp = new Node(x);
    temp->next = head;
    head = temp;
    return true;
}

int Stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
        return INT_MIN;
    }

    else
    {
        Node *temp = head;
        head = head->next;
        int popped = temp->data;
        delete temp;

        return popped;
    }
}

int Stack::peek()
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
        return INT_MIN;
    }
    else
    {
        return head->data;
    }
}

bool Stack::isEmpty()
{
    return head == NULL;
}

bool Stack::isFull()
{
    Node *temp = new Node(0);
    bool result = (temp == NULL);

    delete temp;

    return result;
}

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element is " << s.peek() << endl;

    s.pop();

    cout << "Top element is " << s.peek() << endl;

    return 0;
}