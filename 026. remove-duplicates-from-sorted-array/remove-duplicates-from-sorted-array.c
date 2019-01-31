int removeDuplicates(int* nums, int numsSize) {
    int i, first_zero=numsSize+1, count=0, val=nums[0];
    for(i=1;i<numsSize;i++)
    {
        if(nums[i]==val)
        {
            if(first_zero>=numsSize) first_zero = i;
            nums[i]=0;
            count++;
        }
        else
        {
            if(nums[i]!=val) val = nums[i];
            if(first_zero<numsSize) 
            {
                nums[i] = nums[i]^nums[first_zero];
                nums[first_zero] = nums[i]^nums[first_zero];
                nums[i] = nums[i]^nums[first_zero];
                first_zero = (nums[first_zero+1]==0? first_zero+1:i); 
            }
        }
        //printf("i:%d   first_zero:%d   val:%d count:%d\n",i,first_zero,val,count);
    }
    return numsSize - count;
}
