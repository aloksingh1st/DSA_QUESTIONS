int dnf(vector<int> nums){

int l =0 , h = nums.size()-1;

        while(l < h){
            if(nums[l] < 0){
                l++;
            }
            else if (nums[h] > 0){
                h++;
            }
            else{
                swap(nums[l], nums[h]);
                l++, h++;
            }
        }
}
