class Solution {
public:
    string convert(string s, int numRows) {
        int count = 0;
        int index = 0;
        bool cond = true;
        string hash[numRows];
        string zigzag;
        if (numRows <= 1) return s;
        while (count < s.size())
        {
            hash[index] += s[count];
            if (cond) index++;
            else index--;
            count++;
            if (!(count % (numRows - 1))) cond = !cond;
        }
        for (int i=0; i<numRows; i++) {
            zigzag += hash[i];
        }
        return zigzag;
    }
};
