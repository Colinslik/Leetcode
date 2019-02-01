char* reverseString(char* s) {
    int i,tail=strlen(s)-1;
    for(i=0;i<strlen(s)/2;i++)
    {
       // printf("1.s[%d]:%c   s[%d]:%c\n",i,s[i],strlen(s)-1-i,s[strlen(s)-1-i]);
        s[i] = s[i]^s[tail-i];
        s[tail-i] = s[i]^s[tail-i];
        s[i] = s[i]^s[tail-i];
    }
    return s;
}
