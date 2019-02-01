struct linklist{
    int key;
    int val;
    struct linklist* next;
};

int abs(int val)
{
    return val>0?val:-val;
}

int hash(int* nums, int numsSize,struct linklist* hash_table[])
{
    int i;
    for(i=0;i<numsSize;i++)
    {
        if(!hash_table[abs(nums[i]%100)])
        {
            struct linklist* new_ptr = malloc(sizeof(struct linklist));
            hash_table[abs(nums[i]%100)] = new_ptr;
            new_ptr->key = nums[i];
            new_ptr->val = 1;
            new_ptr->next = '\0';
        }
        else
        {
            struct linklist* ptr = hash_table[abs(nums[i]%100)];
            while(true)
            {
                //printf("ptr->key %d  nums[i] %d\n",ptr->key,nums[i]);
                if(ptr->key==nums[i])
                {
                    //printf("same %d\n",nums[i]);
                    ptr->val++;
                    if(ptr->val > numsSize/2) return ptr->key;
                    else break;
                }
                else if(!ptr->next)
                {
                    //printf("different %d\n",nums[i]);
                    struct linklist* new_ptr = malloc(sizeof(struct linklist));
                    new_ptr->key = nums[i];
                    new_ptr->val = 1;
                    new_ptr->next = '\0';
                    ptr->next = new_ptr;
                    break;
                }
                else ptr = ptr->next;
            }
        }
    }
    return nums[numsSize/2];
}

int majorityElement(int* nums, int numsSize) {
    struct linklist* hash_table[100];
    memset(hash_table,'\0',100*sizeof(struct linklist*));
    return hash(nums, numsSize,hash_table);
}
