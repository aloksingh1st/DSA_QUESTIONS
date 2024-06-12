class Solution {
public:
    void sortColors(vector<int>& nums) {
            int arr[3]={0};
    for(int i=0; i<nums.size(); i++){
        arr[nums[i]]++;
    }
    nums.clear();
    for(int i=0; i<arr[0]; i++){
        nums.push_back(0);
    }
    
    for(int i=0; i<arr[1]; i++){
        nums.push_back(1);
    }
    
    for(int i=0; i<arr[2]; i++){
        nums.push_back(2);
    }
    
    }
};