class Solution {
public:
    map<int, map<int, multiset<int>>> m;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<tuple<TreeNode*, int, int>> q;
        q.push({root, 0, 0});

        while (!q.empty()) { 
            auto [temp, x, y] = q.front();
            q.pop();
            m[x][y].insert(temp->val);
            if (temp->left) {
                q.push({temp->left, x - 1, y + 1});
            }
            if (temp->right) {
                q.push({temp->right, x + 1, y + 1});
            }
        }
        vector<vector<int>> ans;
        for (auto i : m) {
            vector<int> col;
            for (auto j : i.second) {
                col.insert(col.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};