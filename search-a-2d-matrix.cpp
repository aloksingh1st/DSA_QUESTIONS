class Solution {
public:


   bool binarySearch(vector<int> & arr, int k){
    int low = 0, high = arr.size()-1;

    while(low <= high){
        int mid = (low+high)/2;

        if(arr[mid] == k){
            return true;
        }
        else if(arr[mid] > k){
                   high = mid -1;     
        }
        else{
            low = mid+1;
        }
    }

    return false;
   }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        for(int i = 0; i < matrix.size(); i++){
            if(matrix[i][0] <= target && matrix[i][matrix[i].size()-1] >= target){
                if(matrix[i][0] == target){
                    return true;
                }
                return binarySearch(matrix[i], target);
            }
        }

        return false;
    }
};