class Solution {
public:
    int missingNumber(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int i =0;
        int ans;

        for(int j=0;j<nums.size(); j++){
            if(nums[j] == i){
                i++;
            }
            else if(nums[j] > i){
                return i;
            }
            else{
                return ++i;
            }
        }

        return i;
        
    }
};