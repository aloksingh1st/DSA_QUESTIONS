class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
  if (nums.empty()) return 0;  // Handle empty input

        sort(nums.begin(), nums.end());
        int current = nums[0];
        int count = 1;
        int maxCount = 1;  // Track the longest sequence

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) continue;  // Skip duplicates

            if (current + 1 == nums[i]) {
                current++;
                count++;
            } else {
                current = nums[i];
                count = 1;  // Reset for new sequence
            }
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};