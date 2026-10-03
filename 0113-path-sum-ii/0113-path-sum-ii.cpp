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
    void sum(TreeNode* root, int k, vector<vector<int>>& ans,
             vector<int> temp) {
        if (root == NULL)
            return;
        temp.push_back(root->val);
        if (!root->left && !root->right && k - root->val == 0) {
            ans.push_back(temp);
            return;
        }
        sum(root->left, k - root->val, ans, temp);
        sum(root->right, k - root->val, ans, temp);
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return {};
        vector<vector<int>> ans;
        vector<int> temp;
        sum(root, targetSum, ans, temp);
        return ans;
    }
};