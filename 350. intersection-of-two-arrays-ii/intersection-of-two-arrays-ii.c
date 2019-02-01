/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 struct linklist
{
    int val;
    struct linklist* next;
};
 
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    struct linklist* hashtable[10] = {NULL};
    int i;
    *returnSize = 0;
    int* result = malloc(((*returnSize)+1)*sizeof(int*));
    for(i=0; i<nums1Size; i++)
    {
        if(!hashtable[nums1[i]%10])
        {
            struct linklist* newPtr = malloc(sizeof(struct linklist));
            newPtr->val = nums1[i];
            newPtr->next = NULL;
            hashtable[nums1[i]%10] = newPtr;
        }
        else
        {
            struct linklist* Ptr = hashtable[nums1[i]%10];
            while(Ptr)
            {
                if(!Ptr->next)
                {
                    struct linklist* newPtr = malloc(sizeof(struct linklist));
                    newPtr->val = nums1[i];
                    newPtr->next = NULL;
                    Ptr->next = newPtr;
                    break;
                }
                else Ptr = Ptr->next;
            }
        }
    }
    for(i=0; i<nums2Size; i++)
    {
        struct linklist* Ptr = hashtable[nums2[i]%10];
        struct linklist* Prev_Ptr = NULL;
        while(Ptr)
        {
            if(nums2[i] == Ptr->val)
            {
                result[(*returnSize)++] = Ptr->val;
                result = realloc(result,((*returnSize)+1)*sizeof(int*));
                //printf("Ptr->val:%d returnSize:%d\n",Ptr->val,*returnSize);
                if(Prev_Ptr) Prev_Ptr->next = Ptr->next;
                else hashtable[nums2[i]%10] = Ptr->next;
                free(Ptr);
                break;
            }
            else
            {
                Prev_Ptr = Ptr;
                Ptr = Ptr->next;
            }
        }
    }
    //printf("result:%d returnSize:%d\n",result[0],*returnSize);
    return result;
}
