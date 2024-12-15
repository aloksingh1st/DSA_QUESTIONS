#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    void reverse(stack<int>& s) {
        // Base condition: if stack is empty, return
        if (s.empty()) {
            return;
        }

        // Remove the top element
        int topElement = s.top();
        s.pop();

        // Recursive call to reverse the remaining stack
        reverse(s);

        // Insert the removed element at the bottom
        insertAtBottom(s, topElement);
    }

private:
    void insertAtBottom(stack<int>& s, int element) {
        // Base condition: if stack is empty, push the element
        if (s.empty()) {
            s.push(element);
            return;
        }

        // Remove the top element
        int topElement = s.top();
        s.pop();

        // Recursive call to insert element at the bottom
        insertAtBottom(s, element);

        // Push the top element back
        s.push(topElement);
    }
};

// Example usage
int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << "Original Stack: ";
    stack<int> temp = s;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    Solution sol;
    sol.reverse(s);

    cout << "Reversed Stack: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
