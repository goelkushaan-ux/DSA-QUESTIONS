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
    int dep(struct TreeNode* root, int ans, int i) {
        if (root == NULL)
            return max(ans, i);
        ans = max(ans, dep(root->left, ans, i + 1));
        ans = max(ans, dep(root->right, ans, i + 1));
        return ans;
    }

    int maxDepth(struct TreeNode* root) { return dep(root, 0, 0); }
};