class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
         int n = nums.size();
        if (n < 2 * k) return false;  // Not enough elements for two adjacent subarrays of length k

        // Array to store whether each subarray of length k is strictly increasing
        vector<bool> isIncreasing(n - k + 1, false);

        // Fill the isIncreasing array
        for (int i = 0; i <= n - k; ++i) {
            bool strictlyIncreasing = true;
            for (int j = i; j < i + k - 1; ++j) {
                if (nums[j] >= nums[j + 1]) {  // Check if the current subarray is strictly increasing
                    strictlyIncreasing = false;
                    break;
                }
            }
            isIncreasing[i] = strictlyIncreasing;
        }

        // Check for two consecutive true values in isIncreasing
        for (int i = 0; i <= n - 2 * k; ++i) {
            if (isIncreasing[i] && isIncreasing[i + k]) {
                return true;
            }
        }

        return false;
    }
};