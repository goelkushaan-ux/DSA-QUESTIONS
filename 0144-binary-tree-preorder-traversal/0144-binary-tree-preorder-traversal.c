/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void preorder(struct TreeNode* root, int* arr, int* top) {
    if (root == NULL) return;
    arr[(*top)++] = root->val;
    preorder(root->left, arr, top);
    preorder(root->right, arr, top);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* arr = (int*)malloc(100 * sizeof(int)); 
    int top = 0;
    preorder(root, arr, &top);
    *returnSize = top;
    return arr;
}