class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both nodes are null, they are the same
        if (!p && !q) return true;
        
        // If one of the nodes is null or their values don't match, they are not the same
        if (!p || !q || p->val != q->val) return false;
        
        // Recursively check the left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
