bool isPalindrome(int x) {
    int reverse=0;
    if(x<10&&x>=0) return 1;
    if(x%10==0) return 0;
    for(;x>=reverse;x/=10)
    {
        if(x/10 == reverse) return 1;
        else
        {
          reverse = reverse*10 + x%10;
          if (x/10 == reverse) return 1;
        }
    }
    return 0;
}
