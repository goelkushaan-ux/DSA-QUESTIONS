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
/*
void inorder(struct TreeNode* root,int *arr,int *top){
    if(root=NULL) return ;
    inorder(root->left, arr, &top);
    arr[(*top)++] = root->val;
    inorder(root->right, arr, &top);
}
 
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
   int *arr=(int *)malloc(100*sizeof(int));
   int top=0;
   inorder(root,arr,&top);
   *returnSize=top;
   return arr;
}*/

void inorder(struct TreeNode* root, int* arr, int* top) {
    if (root == NULL) return;
    inorder(root->left, arr, top);
    arr[(*top)++] = root->val;
    inorder(root->right, arr, top);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* arr = (int*)malloc(100 * sizeof(int)); 
    int top = 0;
    inorder(root, arr, &top);
    *returnSize = top;
    return arr;
}