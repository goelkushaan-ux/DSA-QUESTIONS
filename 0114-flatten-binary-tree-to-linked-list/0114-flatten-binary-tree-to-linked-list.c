/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void preorder(struct TreeNode* root, int* arr, int* top) {
    if (root == NULL) return;
    arr[(*top)++] = root->val;
    preorder(root->left, arr, top);
    preorder(root->right, arr, top);
}

void flatten(struct TreeNode* root) {
    if (root == NULL || (root->left==NULL &&root->right==NULL)) return;
    int* arr = (int*)malloc(2000 * sizeof(int)); 
    int top = 0;
    preorder(root, arr, &top);

    struct TreeNode* current = root;
    current->val = arr[0];
    current->left = NULL;

    for (int i = 1; i < top; i++) {
        current->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        current = current->right;
        current->val = arr[i];
        current->left = NULL;
        current->right = NULL;
    }
    free(arr);
}