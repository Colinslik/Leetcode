int hammingWeight(uint32_t n) {
    int i,temp,output=0;
    for(i=1;i<=32;i++)
    {
        temp = (n>>i)&0x1;
        if(temp) output++;
        output<<1;
    }
    //printf("%x",output);
    return output;
}
