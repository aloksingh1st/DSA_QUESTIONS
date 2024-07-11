class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxSum = INT_MIN;
        int i=0, j=k;
        int sum = 0;

        for (int m=0; m<j; m++){
            sum = sum + nums[m];
            maxSum = sum;
        }

        while (j< nums.size()){
            sum -= nums[i++];
            sum += nums[j++];
            maxSum = max(maxSum, sum);
        }

       return (double)maxSum / k;
    }
};