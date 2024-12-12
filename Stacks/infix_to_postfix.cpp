#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int prec(char op)
    {
        if (op == '+' || op == '-')
            return 1;
        if (op == '*' || op == '/')
            return 2;
        if (op == '^')
            return 3;
        return 0;
    }

    string infixToPostfix(string &s)
    {
        stack<char> st;
        string result = "";

        for (auto ch : s)
        {
            if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '1' && ch <= '9'))
            {
                result += ch;
            }
            else if (ch == '(')
            {
                st.push(ch);
            }
            else if (ch == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    result += st.top();
                    st.pop();
                }

                st.pop();
            }

            else
            {
                while (!st.empty() && prec(ch) <= prec(st.top()))
                {
                    result += st.top();
                    st.pop();
                }

                st.push(ch);
            }
        }

        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }

        return result;
    }
};

int main()
{
    Solution solution;

    string test1 = "a+b*(c^d-e)^(f+g*h)-i";
    string test2 = "A*(B+C)/D";
    string test3 = "x+y*z/w+u";

    cout << "Postfix of test1: " << solution.infixToPostfix(test1) << endl;
    cout << "Postfix of test2: " << solution.infixToPostfix(test2) << endl;
    cout << "Postfix of test3: " << solution.infixToPostfix(test3) << endl;
}