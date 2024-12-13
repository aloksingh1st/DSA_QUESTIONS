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
        return true;
    }
    return false;
}

// Convert prefix to Postfix expression
string preToPost(string pre_exp)
{
    stack<string> st;
    string temp;
    string operator1;
    string operator2;

    for (int i = pre_exp.size()-1; i >= 0; i--) 
    {
        char ch = pre_exp[i];
        if (isalpha(ch))
        {
            st.push(string(1, ch));
        }
        else
        {
            operator1 = st.top();
            st.pop();
            operator2 = st.top();
            st.pop();
            temp = operator1 + operator2 + ch;

            st.push(temp);
        }
    }

    return st.top();
}

// Driver Code
int main()
{
    string pre_exp = "*-A/BC-/AKL";
    cout << "Postfix : " << preToPost(pre_exp);
    return 0;
}