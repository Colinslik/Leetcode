/*int combinations(int step2,int step1)
{
    int base,insert,sum=1,divisor=1,i;
    if(step2>step1)
    {
        base = step2+1;
        insert = step1;
    }
    else
    {
        base = step1+1;
        insert = step2;
    }
    for(i=base-insert+1;i<=base;i++) sum*=i;
    if(insert==0) divisor = sum;
    else for(i=1;i<=insert;i++) divisor*=i;
    //printf("base:%d  insert:%d  sum:%d\n\n",base,insert,sum/divisor);
    return sum/divisor;
}*/

int permutations(int step2,int step1)
{
    int divisor=1,dividend;
    double sum=1;
    //printf("step2:%d step1:%d\n",step2,step1);
    for(dividend=step2+1;dividend<=step2+step1;dividend++)
    {
       // printf("dividend:%d divisor:%d\n",dividend,divisor);
        sum*=dividend;
        sum/=divisor++;
        //printf("temp:%f\n",sum);
    }
    //printf("sum:%f\n\n",sum);
    return sum;
}

int climbStairs(int n) {
    int i, sum=0;
    for(i=0;i<=n/2;i++)
    {
        /*if( i>1 && (n-2*i)>1 )
        {
            printf("\nif\n");
            for(j=1;j<=i;j++) sum+=combinations(j,(n-2*i));
            printf("end if\n\n");
        }
        else
        {
            sum+=combinations(i,(n-2*i));
        }*/
        sum+=permutations(i,(n-2*i));
    }
    return sum;
}
