class Solution {
private:
    int idx = 0;
    int length = 0;
    void findPalindrome(string s, int left, int right) {
        //cout << left << " " <<right << endl;
        //cout << s.substr(left, right - left + 1)<< endl;
        while (left >=0 && right <= s.length() - 1 && s[left] == s[right]) {
            if (length < right - left + 1) {
                idx = left;
                length = right - left + 1;
            }
            left--;
            right++;
        }
    } 
    
public:
    string longestPalindrome(string s) {
        if (s.length() < 2) {
            return s;
        }
        for (int i = 0; i < s.length() - 1; i++) {
            findPalindrome(s, i, i);
            findPalindrome(s, i, i + 1);
        }
        //cout << idx << " "<<length<<endl;
        return s.substr(idx, length);
    }
};
