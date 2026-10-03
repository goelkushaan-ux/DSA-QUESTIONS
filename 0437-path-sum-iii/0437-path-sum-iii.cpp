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
    int sum(TreeNode* root, long long targetSum) {
        if (root == NULL)
            return 0;
        int ans = 0;
        if (targetSum - root->val == 0)
            ans++;
        ans += sum(root->left, targetSum - root->val);
        ans += sum(root->right, targetSum - root->val);
        return ans;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return 0;

        return sum(root, targetSum) + pathSum(root->left, targetSum) +
               pathSum(root->right, targetSum);
    }
};