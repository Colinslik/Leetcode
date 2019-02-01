/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
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
int maxDepth(struct TreeNode* root) {
    int max=1700;
    struct TreeNode** stack = (struct TreeNode**)malloc(max * sizeof(struct TreeNode*));
    int depth=0,top=0,sum=0;
    struct TreeNode* Ptr=root;
    struct TreeNode* Ptr_pre=root;
    if(Ptr)
    {
        push(stack,Ptr,&top,&max);
        depth++;
    }
    else return 0;
    while(true)
    {
        if(Ptr->left)
        {
            push(stack,Ptr,&top,&max);
            Ptr_pre = Ptr;
            Ptr = Ptr->left;
            Ptr_pre->left = NULL;
            depth++;
        }
        else if(Ptr->right)
        {
            push(stack,Ptr,&top,&max);
            Ptr_pre = Ptr;
            Ptr = Ptr->right;
            Ptr_pre->right = NULL;
            depth++;
        }
        else
        {
            if(top==0) break;
            Ptr = pop(stack,&top);
            if(sum<depth) sum = depth;
            depth--;
        }
    }
    free(stack);
    return sum;
}
