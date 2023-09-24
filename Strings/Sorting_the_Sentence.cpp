#include <bits/stdc++.h>
using namespace std;

int main()
{

    string ans[100];
    string an = "";
    string s = "Myself2 Me1 I4 and3";
    string sentence;

    for (char a : s)
    {
        if (isdigit(a))
        {
            ans[a] = an;
            an = "";
        }
        else if(a !=  ' ')
        {
            an.push_back(a);
        }
        else{
            continue;
        }
    }

    int sizeOfArray = sizeof(ans) / sizeof(ans[0]);

    for (int i = 0; i < sizeOfArray; i++)
    {
        if (ans[i] == "")
        {
            continue;
        }
        else{
        sentence += ans[i] + " "; // Add each word followed by a space
        }
    }

    if (!sentence.empty())
    {
        sentence.pop_back();
    }
    cout << sentence << endl;

    return 0;
}