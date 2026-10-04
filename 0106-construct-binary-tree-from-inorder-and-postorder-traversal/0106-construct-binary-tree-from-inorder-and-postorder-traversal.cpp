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
    TreeNode* build(vector<int>& postorder, int p_start, int p_end,
                    vector<int>& inorder, int i_start, int i_end,
                    map<int, int>& mp) {
        if (p_start > p_end || i_start > i_end)
            return NULL;
        TreeNode* temp = new TreeNode(postorder[p_end]);
        int in_root = mp[temp->val];
        int nums_left = in_root - i_start;
        temp->left = build(postorder, p_start , p_start + nums_left-1, inorder,
                           i_start, in_root - 1, mp);
        temp->right = build(postorder, p_start + nums_left , p_end-1, inorder,
                            in_root + 1, i_end, mp);
        return temp;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mp;
        int n = postorder.size();
        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;
        TreeNode* root = build(postorder, 0, n - 1, inorder, 0, n - 1, mp);
        return root;
    }
};