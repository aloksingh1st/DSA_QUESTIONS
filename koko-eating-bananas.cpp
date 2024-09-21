class Solution {
public:

    long long returnhours(vector<int>& piles, int k){
        long long count = 0;  // Use long long to store the count to avoid overflow
        for(int i = 0; i < piles.size(); i++){
            // Using long long to prevent overflow when adding large numbers
            count += (long long)(piles[i] + k - 1) / k;
        }

        return count;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        sort(piles.begin(), piles.end());
        int low = 1;
        int high = piles[piles.size() - 1];
        int ans;

        while(low <= high){
            int mid = (low + high) / 2;
            long long totalHours = returnhours(piles, mid);  // Using long long to store large sums

            if(totalHours <= h){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};
