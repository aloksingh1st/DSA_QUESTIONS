class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for (int num : nums) {
        if (num < k) {
            return -1; // Impossible if any number is less than k
        }
    }

    // Step 2: Sort the array in descending order
    sort(nums.rbegin(), nums.rend());

    int operations = 0;
    int n = nums.size();

    // Step 3: Iterate over the array to perform operations
    for (int i = 0; i < n; ) {
        if (nums[i] == k) break; // All elements are k
        int curr = nums[i];
        
        // Find the next distinct value or stop at `k`
        while (i < n && nums[i] == curr) {
            nums[i] = k; // Reduce the current segment to k
            ++i;
        }

        ++operations; // Count this operation
    }

    return operations;
    }
};