class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> son(n);
        for (int i = 0; i < n; ++i) {
            auto it = find(nums2.begin(), nums2.end(), nums1[i]);
            bool found = false;
            for (auto j = it + 1; j != nums2.end(); ++j) {
                if (*j > nums1[i]) {
                    son[i] = *j;
                    found = true;
                    break;
                }
            }
            if (!found)
                son[i] = -1;
        }
        return son;
    }
};