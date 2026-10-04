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
    TreeNode* build(vector<int>& preorder, int p_start, int p_end,
                    vector<int>& inorder, int i_start, int i_end,
                    map<int, int>& mp) {
        if (p_start > p_end || i_start > i_end)
            return NULL;
        TreeNode* temp = new TreeNode(preorder[p_start]);
        int in_root = mp[temp->val];
        int nums_left = in_root - i_start;
        temp->left = build(preorder, p_start + 1, p_start + nums_left, inorder,
                           i_start, in_root - 1, mp);
        temp->right = build(preorder, p_start + nums_left + 1, p_end, inorder,
                            in_root + 1, i_end, mp);
        return temp;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mp;
        int n = preorder.size();
        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;
        TreeNode* root = build(preorder, 0, n - 1, inorder, 0, n - 1, mp);
        return root;
    }
};