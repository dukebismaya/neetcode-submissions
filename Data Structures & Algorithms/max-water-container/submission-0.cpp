class Solution {
public:
    int maxArea(vector<int>& heights) {
        int start = 0;
        int end = heights.size()-1;
        int get_max_area = 0;
        while (start<end){
            int get_height = std::min(heights[start], heights[end]);
            int get_width = end-start;
            get_max_area = std::max(get_max_area, get_height*get_width);
            if (heights[start]<heights[end])
                start++;
            else
                end--;
        }
        return get_max_area;
    }
};
