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

 void postorder(struct TreeNode* root, int* arr, int* top) {
    if (root == NULL) return;
    postorder(root->left, arr, top);
    postorder(root->right, arr, top);
    arr[(*top)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
     int* arr = (int*)malloc(100 * sizeof(int)); 
    int top = 0;
    postorder(root, arr, &top);
    *returnSize = top;
    return arr;
}