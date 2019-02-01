/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int Depth(struct TreeNode* root)
{
    if(!root) return 0;
    else 
    {
        int left_sub=Depth(root->left);
        if(left_sub>=100) return 100;
        int right_sub=Depth(root->right);
        if(right_sub>=100) return 100;
        int var=left_sub-right_sub;
        int sum=1+(var>0?left_sub:right_sub);
        if(var<2 && var>-2) return sum;
        else return 100;
    }
}
bool isBalanced(struct TreeNode* root) {
    if(!root) return 1;
    else
    {
        int left_sub=Depth(root->left);
        int right_sub=Depth(root->right);
        if(right_sub>=100 || left_sub>=100) return 0;
        int var=left_sub-right_sub;
        if(var<2 && var>-2) return 1;
        else return 0;
    }
}
