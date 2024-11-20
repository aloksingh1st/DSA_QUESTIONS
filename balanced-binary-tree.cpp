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


 int findHleft(TreeNode* node) {
        if (node == nullptr) return 0; // Base case
        return 1 + std::max(findHleft(node->left), findHleft(node->right));
    }

    int findHright(TreeNode* node) {
        if (node == nullptr) return 0; // Base case
        return 1 + std::max(findHright(node->left), findHright(node->right));
    }

    bool isBalanced(TreeNode* root) {
        if(root== NULL){
            return true;
        }

        int lhs = findHleft(root->left);
        int rhs = findHleft(root->right);


        if(abs(rhs-lhs) > 1) return false;

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        if(!left || !right) return false;
        
        return true;
    }
};