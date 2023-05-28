#include <bits/stdc++.h>
using namespace std;

int main()
{

    stack<char> ans;
    string s = "leet**cod*e";

    for (auto i : s)
    {
        if (i == '*')
        {
            ans.pop();
        }
        ans.push(s[i]);
        i++;
    }

    while (!ans.empty())
    {
        cout<<"ans"<<endl;
        cout << ans.top() << endl;
        ans.pop();
    }

    return 0;
}