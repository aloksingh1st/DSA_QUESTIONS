class Solution {
public:

    // Function to find the maximum element in the given column
    int getMax(vector<vector<int>>& mat, int n, int mid){
        int maxNum = INT_MIN;
        int rowIndex = 0;

        // Iterate through the rows to find the maximum element in the mid column
        for(int i = 0; i < n; i++){
            if (mat[i][mid] > maxNum) {
                maxNum = mat[i][mid];
                rowIndex = i; // Store the row index of the max element
            }
        }

        return rowIndex; // Return the row index of the max element
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low = 0, high = mat[0].size() - 1;
        int n = mat.size();    // Number of rows
        int m = mat[0].size(); // Number of columns

        while(low <= high){
            int mid = (low + high) / 2;

            // Find the row index with the maximum element in the mid column
            int rowIndex = getMax(mat, n, mid);

            // Check the values of the neighbors in the left and right columns
            int left = (mid - 1 >= 0) ? mat[rowIndex][mid - 1] : -1;
            int right = (mid + 1 < m) ? mat[rowIndex][mid + 1] : -1;

            // If the current element is greater than its neighbors, it's a peak
            if (mat[rowIndex][mid] > left && mat[rowIndex][mid] > right) {
                return {rowIndex, mid}; // Return the peak coordinates
            }

            // If the left neighbor is greater, move to the left half
            else if (left > mat[rowIndex][mid]) {
                high = mid - 1;
            }
            // Otherwise, move to the right half
            else {
                low = mid + 1;
            }
        }
        return {-1, -1}; // Return -1, -1 if no peak is found
    }
};
