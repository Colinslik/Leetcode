bool isPalindrome(char* s) {
    int left = 0, right = 0;
    bool empty=true,checked=false;
    right = strlen(s)-1;
    if(right<0) return 1;
    for(left=0;left<=right;left++)
    {
        if(isalnum(s[left])) empty= false;
        if(!isalnum(s[left])) continue;
        else
        {
            for(;right>0;right--)
            {
              if(!isalnum(s[right])) continue;
              else
              {
                  if(tolower(s[left]) != tolower(s[right])) return 0;
                  else 
                  {
                      right--;
                      checked = true;
                      break;
                  }
              }
            }
        }
    }
    if(empty) return 1;
}
