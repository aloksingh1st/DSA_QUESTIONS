class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int res=0;
        int n=size(nums);
        for(int s=0;s<n;s++){
            int sum=0;
            int flag=0;
            for(int e=s;e<n;e++){
                sum+=nums[e];
                if(sum==goal){
                    flag=1;
                    res++;
                    e++;
                    while(e<n && nums[e]==0){
                        e++;
                        res++;
                    }                   
                    break;
                }
            }
            if(flag==0 && goal!=0)break;
        }
        return res;
    }
};