class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l=0, h=arr.size()-1;
        vector<int> ans;

        while(h-l >= k){
            if(x- arr[l] > arr[h]-x){
                l++;
            }
            else{
                h--;
            }
        }

        for(int i=l ; i<=h; i++){
            ans.push_back(arr[i]);
        }

        return ans;
    }
};