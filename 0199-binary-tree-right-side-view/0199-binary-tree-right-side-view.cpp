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
    void temp(TreeNode* root, vector<int>& ans, int i) {
        if (root == NULL)
            return;
        if (ans.size() == i)
            ans.push_back(root->val);
        temp(root->right, ans, i + 1);
        temp(root->left, ans, i + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        temp(root, ans, 0);
        return ans;
    }
};