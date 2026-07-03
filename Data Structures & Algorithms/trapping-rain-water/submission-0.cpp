class Solution {
   public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int get_area = 0;
        int max_left = height[left];
        int max_right = height[right];
        while (left<right) {
            if (max_left<max_right){
                left++;
                max_left = max(height[left], max_left);
                get_area += max_left - height[left];
            } else {
                right--;
                max_right = max(height[right], max_right);
                get_area += max_right - height[right];
            }
        }
        return get_area;
    }
};
