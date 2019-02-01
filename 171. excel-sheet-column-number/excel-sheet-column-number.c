int titleToNumber(char* s) {
    int digit,sum=0;
    for(digit=0;digit<strlen(s);digit++)
    {
        sum += (pow(26, (strlen(s)-digit-1))*(s[digit]-64));
    }
    //printf("sum:%d\n",sum);
    return sum;
}
