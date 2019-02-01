/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
void push(struct TreeNode* stack[],struct TreeNode* Ptr,int* top,int* max)
{
    if((*top)==(*max))
    {
        (*max)+=100;
        struct TreeNode** stack2 = (struct TreeNode**)realloc(stack, (*max) * sizeof(struct TreeNode*));
        if(!stack2)
        { 
            free(stack);
            stack = stack2;
        }
    }
    stack[(*top)++] = Ptr;
}
struct TreeNode* pop(struct TreeNode* stack[],int* top)
{
    return stack[--(*top)];
}
char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    int max=100,printer_size=20;
    struct TreeNode** stack = (struct TreeNode**)malloc(max * sizeof(struct TreeNode*));
    int top=0,sum=0,pop_flag=0,i;
    struct TreeNode* Ptr=root;
    struct TreeNode* Ptr_pre=root;
    char* printer = (char*)malloc(printer_size * sizeof(char*));
    char** output = (char**)malloc(1 * sizeof(char**));

    if(!Ptr) return 0;
    
    while(true)
    {
        //printf("Ptr->val:%d  top:%d\n",Ptr->val,top);
        if(Ptr->left)
        {
            push(stack,Ptr,&top,&max);
            Ptr_pre = Ptr;
            Ptr = Ptr->left;
            Ptr_pre->left = NULL;
            pop_flag=0;
        }
        else if(Ptr->right)
        {
            push(stack,Ptr,&top,&max);
            Ptr_pre = Ptr;
            Ptr = Ptr->right;
            Ptr_pre->right = NULL;
            pop_flag=0;
        }
        else
        {
            if(top==0 && pop_flag) break;
            if(!pop_flag)
            {
               
                /*for(i=0;i<top;i++) printf("%d->",stack[i]->val);
                printf("%d\n",Ptr->val);*/
                
                printer[0]='\0';
                for(i=0;i<top;i++) snprintf(printer + strlen(printer),printer_size,"%d->",stack[i]->val);
                snprintf(printer + strlen(printer),printer_size,"%d",Ptr->val);
                
                output = (char**)realloc(output,++(*returnSize) * sizeof(char**));
                output[(*returnSize)-1] = (char*)malloc(printer_size * sizeof(char*));
                strcpy(output[(*returnSize)-1],printer);
                //printf("printer_size:%d  returnSize:%d\n",printer_size,*returnSize);
            }
            if(top>0) Ptr = pop(stack,&top);
            else break;
            pop_flag=1;
        }
    }
    /*for(i=0;i<(*returnSize);i++)
    {
      printf("%s\n",output[i]);
    }*/
    free(stack);
    free(printer);
    return output;
}
