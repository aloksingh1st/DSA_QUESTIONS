#include <bits/stdc++.h>
using namespace std;

int main(){

    int T;
    cin >> T;

    while(T--){

        float n;
        int x;
        cin>>n>>x;

        if(x >= ceil(n/2)){
            cout <<"YES"<<endl;
        }

        else{
            cout<<"NO"<<endl;
        }
    }

    return 0;   
    }