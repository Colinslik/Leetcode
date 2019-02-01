bool isAnagram(char* s, char* t) {
    int i,j, count = strlen(t);
    if(strlen(s) != strlen(t)) return 0;
    for(i=0;i<strlen(s);i++)
    {
        //printf("count:%d  s:%s  t:%s\n\n",count,s,t);
        for(j=0;j<count;j++)
        {
            //printf("s[%d]:%c t[%d]:%c\n",i,s[i],j,t[j]);
            if(s[i] == t[j])
            {
                t[j] = t[j]^t[count-1];
                t[count-1] = t[j]^t[count-1];
                t[j] = t[j]^t[count-1];
                count--;
                break;
            }
        }
    }
   // printf("\ncount:%d\n",count);
    return !count;
}
