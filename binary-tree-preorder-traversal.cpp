class Solution {
public:
    vector<int> res;
    void rec(TreeNode* root) {
        if (!root) return;
        res.push_back(root->val);
        rec(root->left);
        rec(root->right);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        rec(root);
        return res;
    }
};