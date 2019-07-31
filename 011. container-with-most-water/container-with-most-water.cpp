class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() < 1) {
            return 0;
        }
        map<int, int> height_map;
        map<int, int>::iterator it;
        int left_area = 0;
        int right_area = 0;
        int max_area = 0;
        for (int i=0; i<height.size(); i++) {
            it = height_map.find(i);
            if (it != height_map.end()) continue;
            for (int j=0; j<i; j++) {
                if (height[j] >= height[i]) {
                    left_area = height[i] * (i - j);
                    break;
                }
            }
            for (int j=height.size()-1; j>i; j--) {
                if (height[j] >= height[i]) {
                    right_area = height[i] * (j - i);
                    break;
                }
            }
            if (left_area > max_area && left_area > right_area) {
                max_area = left_area;
            }
            else if (right_area > max_area && right_area > left_area) {
                max_area = right_area;
            }
            height_map.insert ( make_pair(i ,max_area) );
        }
        //for (it=height_map.begin() ;it != height_map.end(); it++) {
        //        cout << it->first << " "<< it->second <<endl;
        //}
        return max_area;
    }
};
