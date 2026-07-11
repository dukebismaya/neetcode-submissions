class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int height_size = heights.size();
        int maxArea{};
        for (size_t i = 0; i < height_size; ++i) {
            auto curr_height = heights[i];
            int left = i;
            int right = i + 1;
            while (left >= 0 && heights[left] >= curr_height) {
                left--;
            }
            while (right < height_size && heights[right] >= curr_height) {
                right++;
            }
            left++;
            right--;
            maxArea = std::max(maxArea, (right - left + 1) * curr_height);
        }
        return maxArea;
    }
};
