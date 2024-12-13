#include <iostream>
#include <stack>
using namespace std;

// function to check if character is operator or not
bool isOperator(char x)
{
    switch (x)
    {
    case '+':
    case '-':
    case '/':
    case '*':
    case '^':
    case '%':
        return true;
    }
    return false;
}

// Convert prefix to Infix expression
string preToInfix(string pre_exp)
{
    stack<string> st;
    string temp;

    for (auto ch : pre_exp)
    {
        if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9')
        {
            // st.push(ch);
            st.push(string(1, ch));
        }

        else
        {
            temp = '(' + st.top() + ch;
            st.pop();
            temp += st.top() + ')';
            st.pop();

            st.push(temp);
        }
    }

    return st.top();
}

// Driver Code
int main()
{
    string pre_exp = "*-A/BC-/AKL";
    cout << "Infix : " << preToInfix(pre_exp);
    return 0;
}