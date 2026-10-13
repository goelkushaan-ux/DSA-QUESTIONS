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
    void pre(TreeNode* root, vector<int>& a) {
        if (root == NULL)
            return;
        pre(root->left, a);
        a.push_back(root->val);
        pre(root->right, a);
    }

public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> a;
        pre(root, a);
        int l = 0, r = a.size() - 1;
        while (l < r) {
            int sum = a[l] + a[r];
            if (sum == k)
                return true;
            if (sum > k)
                r--;
            else
                l++;
        }
        return false;
    }
};