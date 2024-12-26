class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, maxCount = 0, zeroes = 0, count = 0;

        while(r < nums.size()){
            if(nums[r] == 0){
                zeroes++;
            }

            while (zeroes > k) {
                if (nums[l] == 0) {
                    zeroes--;
                }
                l++;
            }

      maxCount = max(maxCount, r - l + 1);

            r++;
        }

        return maxCount;

    }
};