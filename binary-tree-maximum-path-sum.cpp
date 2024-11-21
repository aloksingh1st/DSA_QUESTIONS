/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxi = INT_MIN;
    int sum(TreeNode* root){
        if(!root) return 0;
        int lsum=0, rsum=0;
        lsum = max(0, sum(root->left));
        rsum = max(0, sum(root->right));

        maxi = max(maxi, lsum + rsum + root->val);
        return root->val + max(lsum,rsum);  // pass along the best-
                           // path to the node above for making the max sum.                       
    }

    int maxPathSum(TreeNode* root) {
        int ans = sum(root);
        return maxi;
    }
};