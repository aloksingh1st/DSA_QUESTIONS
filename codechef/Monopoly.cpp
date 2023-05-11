#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){

        int p, q, r, s;

        cin >> p >> q >> r >> s;

        int qrs = q+r+s;
        int prs = p+r+s;
        int pqs = p + q+ s;
        int pqr = p + q + r;

        if(p > qrs || q > prs || r > pqs || s > pqr){
            cout<< "YES"<<endl;
        }
        else{
            cout<< "NO"<<endl;
            
        }
    }

    return 0;
}