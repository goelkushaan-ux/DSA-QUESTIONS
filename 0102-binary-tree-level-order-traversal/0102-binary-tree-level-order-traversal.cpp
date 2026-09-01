/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void traversal(vector<vector<int>>& ans, TreeNode* root, int i) {
        if (root == NULL)
            return;
        if (ans.size() == i)
            ans.push_back({});
        ans[i].push_back(root->val);
        traversal(ans, root->left, i + 1);
        traversal(ans, root->right, i + 1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL)
            return {};
        vector<vector<int>> ans;
        traversal(ans, root, 0);
        return ans;
    }
};