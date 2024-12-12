#include <bits/stdc++.h>
using namespace std;

#define max 1000

class Stack
{

    int top;

public:
    int arr[max];
    Stack()
    {
        top = -1;
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
    else
    {
        arr[++top] = x;
        cout << x << " pushed to stack" << endl;
        return true;
    }
}

int Stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack Underflow" << endl;
        return INT_MIN;
    }
    else
    {
        int x = arr[top--];
        return x;
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
        return arr[top];
    }
}

bool Stack::isEmpty()
{
    return (top == -1);
}

bool Stack::isFull()
{
    return (top == max - 1);
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