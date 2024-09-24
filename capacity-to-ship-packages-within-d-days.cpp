class Solution {
public:

    int getMax(vector<int>& arr){
        int maxEle = INT_MIN;
        for(int i=0; i< arr.size(); i++){
            maxEle = max(maxEle, arr[i]);
        }

        return maxEle;
    }

    int getSum(vector<int>& arr){
        int sum = 0;

        for(int i=0; i< arr.size(); i++){
            sum+=arr[i];
        }

        return sum;
    }

    bool canTake(vector<int>& arr, int days, int mid){
         int day = 1;  // We start with the first day
    int currentCout = 0;

    for(int i = 0; i < arr.size(); i++) {
        if(currentCout + arr[i] > mid) {
            // If adding arr[i] exceeds the current limit (mid),
            // we need a new day.
            day++;
            currentCout = arr[i];  // Start new day with the current element
            if(day > days) {
                return false;  // If days exceed the limit, return false
            }
        } else {
            // If within the limit, keep adding to the current day
            currentCout += arr[i];
        }
    }

    return true;  // If we fit within the given number of days
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = getMax(weights);
        int high = getSum(weights);
        int ans;

        while(low <= high){
            int mid = (low+high)/2;
            int cantake = canTake(weights, days, mid);

            if(cantake){
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