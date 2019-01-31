int removeElement(int* nums, int numsSize, int val) {
    int i, first_zero=numsSize+1, count=0;
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]==val)
        {
            if(first_zero>=numsSize) first_zero = i;
            count++;
        }
        else
        {
            if(first_zero<numsSize) 
            {
                nums[i] = nums[i]^nums[first_zero];
                nums[first_zero] = nums[i]^nums[first_zero];
                nums[i] = nums[i]^nums[first_zero];
                first_zero = (nums[first_zero+1]==val? first_zero+1:i); 
            }
        }
        //printf("i:%d   first_zero:%d    count:%d\n",i,first_zero,count);
    }
    return numsSize - count;
}
