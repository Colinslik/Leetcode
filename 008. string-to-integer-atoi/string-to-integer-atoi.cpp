class Solution {
public:
    int myAtoi(string str) {
        size_t found = str.find_first_not_of(" ");
        int minus = 1;
        int sum = 0;
        if (found!=std::string::npos) {
            if (static_cast<int>(str[found]) == 43 || 
                static_cast<int>(str[found]) == 45 || 
                (static_cast<int>(str[found]) <= 57 && 
                 static_cast<int>(str[found]) >= 48)) {
                
                if (static_cast<int>(str[found]) == 45) {
                    minus = -1;
                    found++;
                }
                else if (static_cast<int>(str[found]) == 43) {
                    found++;
                }
                string my_substr = str.substr(found); 
                found = my_substr.find_first_not_of("1234567890");
                my_substr = my_substr.substr(0, found);
                while (!my_substr.empty()) {
                    if (sum != 0 && (
                        (numeric_limits<int>::max() / sum < 10) || 
                        (numeric_limits<int>::min() / sum > -10))) {
                        return ((minus > 0)?
                                numeric_limits<int>::max() :
                                numeric_limits<int>::min());
                    }
                    else sum *= 10;
                    if (sum != 0 && (
                        (numeric_limits<int>::max() - sum < (static_cast<int>(my_substr.front()) - 48)) || 
                        (numeric_limits<int>::min() + sum > -1 * (static_cast<int>(my_substr.front()) - 48)))) {
                        return ((minus > 0)?
                                numeric_limits<int>::max() : 
                                numeric_limits<int>::min());
                    }
                    else sum += (static_cast<int>(my_substr.front()) - 48);
                    my_substr.erase(0,1);
                }
                return sum * minus;
            }
        }
        return 0;
    }
};
