bool isHappy(int n) {
    int table[10];
    memset(table,-1,sizeof(int)*10);
    int result = n,count = 0,sum=0;
    while(result!=1 && count < 100)
    {
        for(;result!=0;result/=10)
        {
            if(table[result%10]==-1) 
            {
                table[result%10] = (result%10)*(result%10);
            }
            sum+=table[result%10];
        }
        result = sum;
        sum = 0;
        count ++;
    }
    return (result==1)?1:0;
}
