#include <bits/stdc++.h>
using namespace std;

vector<int> moveZeroes(vector<int> &nums){

     vector<int> ans;
        int c = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0){
                ans.push_back(nums[i]);
            }
            else{
                c++;
            }
        }
        for(int i=0; i<c; i++){
            ans.push_back(0);
        }

        for(int i=0; i<ans.size(); i++){
            nums[i] = ans[i];
        }

        return ans;
}

int main(){

    vector<int> arr = {0, 1, 0, 3, 12};
    vector <int> ans = moveZeroes(arr);

    for(auto i : ans){
        cout << i <<endl;
    } 

    return 0;
}