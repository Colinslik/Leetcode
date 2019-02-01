/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int traveling(struct TreeNode* root)
{
    if(!root) return 0;
    traveling(root->left);
    traveling(root->right);
    struct TreeNode* temp;
    temp = root->left;
    root->left = root->right;
    root->right = temp;
   // printf("%d ",root->val);
}
 
struct TreeNode* invertTree(struct TreeNode* root) {
    traveling(root);
    return root;
}
