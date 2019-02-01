/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int traveling(struct TreeNode* p, struct TreeNode* q)
{
    if(!p || !q)
    {
        if(!p && !q) return 1;
        else return 0;
    }
    if(!traveling(p->left,q->left)) return 0;
    if(!traveling(p->right,q->right)) return 0;
   // printf("p:%d q:%d\n",p->val,q->val);
    if(p->val == q->val) return 1;
    else return 0;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
   return traveling(p,q);
}
