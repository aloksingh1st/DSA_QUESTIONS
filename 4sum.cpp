class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& num, int target) {
         vector<vector<int>> res;
        if (num.size() < 4) return res;
        sort(num.begin(),num.end());
        
        for (int i = 0; i < num.size()-3; i++) {
            if(i > 0 && num[i] == num[i-1]) continue;
            
            long long target1 = target - num[i];
            
            for (int j = i + 1; j < num.size()-2; j++) {
                if(j > i+1 && num[j] == num[j-1]) continue;
                
                long long targetSum = target1 - num[j];
                int hi = num.size()-1, lo = j+1;
            
                while(hi > lo) {    
                    long long curSum = num[lo] + num[hi];
                    if (targetSum > curSum) lo++;                
                    else if (targetSum < curSum) hi--;                
                    else {
                        res.push_back({num[i], num[j], num[lo], num[hi]});
                        while (hi > lo && num[lo] == res.back()[2]) lo++;
                        while (hi > lo && num[hi] == res.back()[3]) hi--;
                    }
                }
            }
        }
        return res;
    }
};