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
    int left(TreeNode* root) {
        if (root == NULL)
            return 0;
        return 1 + left(root->left);
    }
    int right(TreeNode* root) {
        if (root == NULL)
            return 0;
        return 1 + right(root->right);
    }

public:
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int l = left(root), r = right(root);
        if (l == r)
            return (1 << l) - 1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};