#include <iostream>
#include <climits>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int findMaxElement(TreeNode *root)
    {

        int maxi = INT_MIN;

        if (root == nullptr)
        {
            return maxi;
        }

        int leftMax = root->left ? findMaxElement(root->left) : INT_MIN;
        int rightMax = root->right ? findMaxElement(root->right) : INT_MIN;

        maxi = max(root->val, max(leftMax, rightMax));

        return maxi;
    }

    bool search(TreeNode *root, int data)
    {
        if (root == nullptr)
        {
            return false; // Base case: empty tree or reached a leaf
        }
        if (root->val == data)
        {
            return true; // Element found
        }
        // Recur on the left and right subtrees
        return search(root->left, data) || search(root->right, data);
    }

    int height(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    // Function to print all nodes at a given level
    void printLevel(TreeNode *root, int level)
    {
        if (root == nullptr)
            return;
        if (level == 1)
            cout << root->val << " ";
        else
        {
            printLevel(root->left, level - 1);
            printLevel(root->right, level - 1);
        }
    }
};

// Example usage (commented for LeetCode-style submission):
int main()
{
    TreeNode *root = new TreeNode(1, new TreeNode(5), new TreeNode(3));
    Solution sol;
    cout << sol.findMaxElement(root) << endl;
    return 0;
}
