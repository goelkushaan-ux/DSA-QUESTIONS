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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;
        long long ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            long long n = q.size();
            long long mini = q.front().second;
            long long first, last;
            for (long long i = 0; i < n; i++) {
                long long cur_index = q.front().second - mini;
                TreeNode* node = q.front().first;
                q.pop();
                if (i == 0)
                    first = cur_index;
                if (i == n - 1)
                    last = cur_index;
                if (node->left != NULL)
                    q.push({node->left, 2 * cur_index + 1});
                if (node->right != NULL)
                    q.push({node->right, 2 * cur_index + 2});
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};