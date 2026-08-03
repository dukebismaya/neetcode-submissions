class Solution {
public:
  int trap(vector<int> &height) {
    int left{}, right = height.size() - 1;
    int area{};
    int left_max_height = height[left], right_max_height = height[right];
    while (left < right) {
      if (left_max_height < right_max_height) {
        left++;
        left_max_height = std::max(height[left], left_max_height);
        area += left_max_height - height[left];
      } else {
        right--;
        right_max_height = std::max(height[right], right_max_height);
        area += right_max_height - height[right];
      }
    }
    return area;
  }
};
