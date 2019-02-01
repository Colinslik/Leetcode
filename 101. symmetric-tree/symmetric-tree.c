/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int left_first_traversal(struct TreeNode* root,int printer[],int* count)
{
    if(!root) return 0;
    else if(left_first_traversal(root->left, printer, count))
    {
        if(left_first_traversal(root->right, printer, count)) printer[(*count)++] = root->val;
        else
        {
            printer[(*count)++] = -100;
            printer[(*count)++] = root->val;
        }
    }
    else
    {
        printer[(*count)++] = -100;
        if(!left_first_traversal(root->right, printer, count)) (*count)--;
        printer[(*count)++] = root->val;
    }
    
    return 1;
}
/*int right_first_traversal_V1(struct TreeNode* root,int printer[],int* count)
{
    if(!root) return 0;
    else if(right_first_traversal(root->right, printer, count))
    {
        if(right_first_traversal(root->left, printer, count)) printer[(*count)++] = root->val;
        else
        {
            printer[(*count)++] = -100;
            printer[(*count)++] = root->val;
        }
    }
    else
    {
        printer[(*count)++] = -100;
        if(!right_first_traversal(root->left, printer, count)) (*count)--;
        printer[(*count)++] = root->val;
    }
    
    return 1;
}*/
int right_first_traversal(struct TreeNode* root,int printer[],int* count)
{
    if(!root) return 0;
    if(right_first_traversal(root->right, printer, count))
    {
        if(right_first_traversal(root->left, printer, count))
        {
            if(printer[(*count)++] != root->val)
            {
                (*count)--;
                return 0;
            }
        }
        else
        {
            if(printer[(*count)++] != -100)
            {
                (*count)--;
                return 0;
            }
            if(printer[(*count)++] != root->val)
            {
                (*count)--;
                return 0;
            }
        }
    }
    else
    {
       // printf("count:%d  printer:%d   val:%d\n\n",(*count),printer[(*count)],root->val);
        if(printer[(*count)++] != -100)
        {
            if(right_first_traversal(root->left, printer, count))
            {
                (*count)--;
                return 0;
            }
            else (*count)--;
        }
        else
        {
            if(!right_first_traversal(root->left, printer, count)) return 0;
        }
  //      printf("count:%d  printer:%d   val:%d\n\n",(*count)-1,printer[(*count)-1],root->val);
        if(printer[(*count)++] != root->val)
        {
            (*count)--;
            return 0;
        }
    }
    
    return 1;
}
bool isSymmetric(struct TreeNode* root) {
    int printer[1000];
    //int printer2[1000];
    int count=0;
    //int count2=0;
    if(!root) return 1;
    else if(!left_first_traversal(root->left,printer,&count))
    {
        count=0;
        if(!right_first_traversal(root->right,printer,&count)) return 1;
        else return 0;
    }
   else
   {
        count=0;
        return right_first_traversal(root->right,printer,&count);
   }
    //right_first_traversal_V1(root->right,printer2,&count2);
    /*int i,bound;
    for(i=0;i<count;i++) printf("%d ",printer[i]);
    printf("\n\n right:\n");
    for(i=0;i<count2;i++) printf("%d ",printer2[i]);
    printf("\n\n");
    if(count!=count2) return 0;
    if(count>count2) bound = count;
    else bound = count2;
    for(i=0;i<bound;i++)
    {
        printf("%d   %d",printer[i],printer2[i]);
        if(printer[i]!=printer2[i]) return 0;
    }
    return 1;*/
}
