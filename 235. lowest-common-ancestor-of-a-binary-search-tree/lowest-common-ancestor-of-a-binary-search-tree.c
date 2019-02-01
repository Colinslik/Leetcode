/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int traveling(struct TreeNode* p, struct TreeNode* q ,struct TreeNode* printer[100],int* count)
{
    if(!p) return 0;
    if(traveling(p->left,q,printer,count))
    {
        //sprintf(printer + strlen(printer),"%d",p->val);
        printer[(*count)++]=p;
        return 1;
    }
    if(traveling(p->right,q,printer,count))
    {
        //sprintf(printer + strlen(printer),"%d",p->val);
        printer[(*count)++]=p;
        return 1;
    }
    if(p->val == q->val)
    { 
        //sprintf(printer + strlen(printer),"%d",p->val);
        printer[(*count)++]=p;
        return 1;
    }
    else return 0;
}
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode* printer[100];
    struct TreeNode* printer2[100];
    struct TreeNode* Ptr;
    int count=0,count2=0;
    memset(printer,'\0',100);
    memset(printer2,'\0',100);
    traveling(root,p,printer,&count);
    traveling(root,q,printer2,&count2);
    int end=count>count2?count2:count,i;
    /*printf("count:%d  count2:%d i:%d\n",count,count2,i);
    for(i=0;i<count;i++) printf("%d ",printer[i]->val);
    printf("\n\n");
    for(i=0;i<count2;i++) printf("%d ",printer2[i]->val);*/
    for(i=0;i<=end;i++)
    {
        Ptr = printer[count-i];
        if(printer[count-1-i] != printer2[count2-1-i]) 
        {
         // printf("\nval:%d\n",printer[count-i]->val);
          break;
        }
    }
    return Ptr;
}
