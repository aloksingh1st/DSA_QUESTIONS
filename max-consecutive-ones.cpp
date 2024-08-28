class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
     int ans = INT_MIN;
     int count = 0;

     for(int i=0; i< nums.size();i++){

        
        if(nums[i] == 1){
            count++;
        }
        else{
            ans = max(ans, count);
            count = 0;
        }

        if(i == nums.size()-1){
            ans = max(ans, count);
        }
     }

     return ans;
    }
};