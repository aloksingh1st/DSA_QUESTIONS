#include <bits/stdc++.h>
using namespace std;

int findGreatestINArray(vector<int> arr){
    sort(arr.begin(), arr.end());
    return arr[arr.size()-1];
}

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    vector<bool> ans;
    int largestCandies = findGreatestINArray(candies);
    for(auto i: candies){
        if(i+extraCandies >= largestCandies){
            ans.push_back(true);
        }
        else{
            ans.push_back(false);
        }
    }

    return ans;
}

int main(){
    vector<int> arr = {2,3,5,1,3};
    int candies = 3;

    vector<bool> a = kidsWithCandies(arr, candies);

    for(auto i: a){
        cout<<i << endl;
    }


    return 0;
}