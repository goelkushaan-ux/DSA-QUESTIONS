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
    bool temp(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL || t2 == NULL)
            return t1 == t2;
        return (t1->val == t2->val) && temp(t1->left, t2->right) &&
               temp(t1->right, t2->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        return temp(root->left, root->right);
    }
};