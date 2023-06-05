#include <bits/stdc++.h>
using namespace std;


int main(){

    vector<int> arr = {1, 2, 7, 6 ,5, 18};
    vector<int> ans;

    sort(arr.begin(), arr.end());
    for(int i=0; i<arr.size(); i++){
        if(i == arr.size() - 1){
            ans.push_back(-1);
        }

        else{
            ans.push_back(arr[i+1]);
        }
    }

    for(auto i : arr){
        cout<< i<< " ";
    }

    cout<<endl;


    for(auto i : ans){
        cout<< i<< " ";
    }


    return 0;
}