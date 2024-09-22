class Solution {
public:
    
 int getMax(vector<int>& bloomDay){
    int ans= INT_MIN;

    for(int i=0; i<bloomDay.size(); i++){
        ans = max(ans, bloomDay[i]);
    }

    return ans;
 }


 int getSum(vector<int>& nums, int mid){
    int sum = 0;
    for(int i =0; i< nums.size(); i++){
        sum += (nums[i] + mid -1)/mid;
    }

    return sum;
 }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = getMax(nums);
        int ans;

        while(low <= high){
            int mid = (low+high)/2;
            int sumans = getSum(nums, mid);

            if(sumans <= threshold){
                ans = mid;
                high = mid-1;
            }
            else{

                low = mid+1;

            }
            
        }

        return ans;
    }
};