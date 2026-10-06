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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* curr = root;
        TreeNode* prev = NULL;
        while (curr != NULL) {
            prev = curr;
            if (val < curr->val)
                curr = curr->left;
            else
                curr = curr->right;
        }
        TreeNode* n = new TreeNode(val);
        if (prev == NULL)
            return n;
        if (val < prev->val)
            prev->left = n;
        else
            prev->right = n;
        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;
        for (int i = 0; i < preorder.size(); i++)
            root = insertIntoBST(root, preorder[i]);
        return root;
    }
};