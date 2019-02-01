struct link_list{
    int val;
    struct link_list* next;
};

int abs(int val)
{
    return val>0? val: -val;
}

bool containsDuplicate(int* nums, int numsSize) {
    struct link_list* hash_table[100];
    int i;
    memset(hash_table,'\0',100*sizeof(struct link_list*));
    for(i=0;i<numsSize;i++)
    {
       // printf("%d :",i);
        if(!hash_table[abs(nums[i]%100)])
        {
            //printf("%d  if\n",nums[i]);
            hash_table[abs(nums[i]%100)] = malloc(sizeof(struct link_list));
            hash_table[abs(nums[i]%100)]->val = nums[i];
            hash_table[abs(nums[i]%100)]->next = '\0';
        }
        else
        {
            //printf("%d  else\n",nums[i]);
            struct link_list* Ptr = hash_table[abs(nums[i]%100)];
            while(Ptr)
            {
                //printf("Ptr->val:%d   nums[i]:%d\n",Ptr->val,nums[i]);
                if(Ptr->val == nums[i]) return 1;
                if(!Ptr->next) break;
                else Ptr = Ptr->next;
                //printf("\nTEST\n");
            }
            Ptr->next = malloc(sizeof(struct link_list));
            Ptr->next->val = nums[i];
            Ptr->next->next = '\0';
        }
    }
    return 0;
}
