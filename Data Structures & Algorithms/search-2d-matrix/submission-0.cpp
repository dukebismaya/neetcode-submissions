class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int left = 0;
        int right = rows * cols - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int mid_val = matrix[mid / cols][mid % cols];
            if (target == mid_val)
                return true;
            else if (target < mid_val)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return false;
    }
};
