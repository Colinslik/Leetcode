class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string char_map = "";
        size_t pos;
        int length = 0;
        while (!s.empty()) {
            pos = char_map.find(s.front());
            if (pos != std::string::npos) {
                char_map.erase(0, pos + 1);
            }
            char_map.push_back(s.front());
            //for (auto it=char_map.begin(); it!=char_map.end(); ++it)
            //    std::cout << ' ' << *it;
            //std::cout << '\n';
            length = ((length < char_map.length())? char_map.length() : length);
            s.erase(0,1);
        }
        return length;
    }
};
