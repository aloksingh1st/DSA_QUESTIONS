class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        map<int, int> ans;

        for(int i=0 ;i< nums.size(); i++){
            ans[nums[i]]++;
        }
        

        for(auto it : ans){
            if(it.second > (n/2)){
                return it.first;
            }
        }

        return -1;
    }
};