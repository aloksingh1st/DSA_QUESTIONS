#include <bits/stdc++.h>
using namespace std;

    bool check(int n)
    {
        if (n > 0 && n % 4 == 0) 
        {
            n = n / 4;
            return check();
        }
		else return n == 1;
    }

int main(){
    int n;
    int ans = check(n);

    cout<<ans<<endl;
    return 0;
}