void moveZeroes(int* nums, int numsSize) {
    int i, first_zero=numsSize+1;
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]==0)
        {
            if(first_zero>=numsSize) first_zero = i;
        }
        else
        {
            if(first_zero<numsSize) 
            {
                nums[i] = nums[i]^nums[first_zero];
                nums[first_zero] = nums[i]^nums[first_zero];
                nums[i] = nums[i]^nums[first_zero];
                first_zero = (nums[first_zero+1]==0? first_zero+1:i); 
            }
        }
        //printf("i:%d   first_zero:%d\n",i,first_zero);
    }
}
