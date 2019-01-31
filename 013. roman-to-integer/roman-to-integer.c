enum{
    I = 1,
    V = 5,
    X = 10,
    L = 50,
    C = 100,
    D = 500,
    M = 1000
};

int sub(char pre, int now)
{
    int sum;
    switch(pre)
    {
        case 'I':
            sum=I;
            break;
        case 'V':
            sum=V;
            break;
        case 'X':
            sum=X;
            break;
        case 'L':
            sum=L;
            break;
        case 'C':
            sum=C;
            break;
        case 'D':
            sum=D;
            break;
        case 'M':
            sum=M;
            break;
        default:
            break;
    }
    //printf("sub:%d \n",now>sum?-(sum*2):0);
    return now>sum?-(sum*2):0;
}

int romanToInt(char* s) {
    int i,sum=0;
    for(i=0;i<strlen(s);i++)
    {
        switch(s[i])
        {
            case 'I':
                sum+=I;
                //printf("I:  %d\n",sum);
                break;
            case 'V':
                if(i!=0) sum+=sub(s[i-1],V);
                sum+=V;
                //printf("V: %d\n",sum);
                break;
            case 'X':
                if(i!=0)  sum+=sub(s[i-1],X);
                sum+=X;
                //printf("X: %d\n",sum);
                break;
            case 'L':
                if(i!=0)  sum+=sub(s[i-1],L);
                sum+=L;
                //printf("L: %d\n",sum);
                break;
            case 'C':
                if(i!=0)  sum+=sub(s[i-1],C);
                sum+=C;
                //printf("C: %d\n",sum);
                break;
            case 'D':
                if(i!=0)  sum+=sub(s[i-1],D);
                sum+=D;
                //printf("D: %d\n",sum);
                break;
            case 'M':
                if(i!=0)  sum+=sub(s[i-1],M);
                sum+=M;
                //printf("M: %d\n",sum);
                break;
            default:
                break;
        }
    }
    return sum;
}
