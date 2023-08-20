#include <bits/stdc++.h>

using namespace std;


void solve( long long n, long long temp, vector<long long> &ans){
    if(n>temp){
        if(temp>0){
            ans.push_back(temp);
        }

        solve(n, (temp*10)+2, ans);
        solve(n, (temp*10)+5, ans);
    }

    else{


    return;
    }
}


vector<long long> createSequence(long long n){
    vector<long long> ans;
    if(n == 2){
        ans.push_back(2);
        return ans;
    }

    long long temp = 0;

    solve(n, temp, ans);
    sort(ans.begin(), ans.end());

    return ans;

}

int main(){

    long long n;
    cin >> n;

    vector<long long> ans;
    if(n == 2){
        ans.push_back(2);
    }

    long long temp = 0;

    solve(n, temp, ans);
    sort(ans.begin(), ans.end());

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}