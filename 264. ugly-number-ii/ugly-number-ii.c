int min(int a, int b)
{
    return (a>=b)?b:a;
}

int nthUglyNumber(int n) {
    int ugly_list[n];
    memset(ugly_list,0,sizeof(int)*n);
    int num2=2,num3=3,num5=5,minVal=0,count=1,num2_count=0,num3_count=0,num5_count=0;
    ugly_list[0]=1;
    for(;count<n;count++)
    {
        minVal = min(min(num2, num3),num5);
        ugly_list[count] = minVal;
        if(minVal == num2) num2 = 2 * ugly_list[++num2_count];
        if(minVal == num3) num3 = 3 * ugly_list[++num3_count];
        if(minVal == num5) num5 = 5 * ugly_list[++num5_count];
    }
    return ugly_list[n-1];
}
