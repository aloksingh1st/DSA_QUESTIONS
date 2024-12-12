#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;

        for (auto ch : s)
        {
            // Push opening brackets onto the stack
            if (ch == '(' || ch == '{' || ch == '[')
            {
                st.push(ch);
            }
            // Handle closing brackets
            else
            {
                // Check if stack is empty or the top doesn't match
                if (st.empty() ||
                    (ch == ')' && st.top() != '(') ||
                    (ch == '}' && st.top() != '{') ||
                    (ch == ']' && st.top() != '['))
                {
                    return false;
                }
                st.pop(); // Pop the matching opening bracket
            }
        }

        // Ensure no unmatched opening brackets remain
        return st.empty();
    }
};

int main()
{
    Solution solution;

    // Test cases
    string test1 = "({[]})";
    string test2 = "([)]";
    string test3 = "{[()]}";
    string test4 = "(";

    // Validate each test case
    cout << "Test 1: " << test1 << " -> " << (solution.isValid(test1) ? "Valid" : "Invalid") << endl;
    cout << "Test 2: " << test2 << " -> " << (solution.isValid(test2) ? "Valid" : "Invalid") << endl;
    cout << "Test 3: " << test3 << " -> " << (solution.isValid(test3) ? "Valid" : "Invalid") << endl;
    cout << "Test 4: " << test4 << " -> " << (solution.isValid(test4) ? "Valid" : "Invalid") << endl;

    return 0;
}
