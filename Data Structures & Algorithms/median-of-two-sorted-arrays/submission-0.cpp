class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        nums1.insert(nums1.begin(), nums2.begin(), nums2.end());
        std::sort(nums1.begin(), nums1.end());
        int mid = (m+n)/2;
        if ((m + n) % 2 == 0) {
            return (double)(nums1[mid] + nums1[mid - 1]) / 2.0;
        }
        return nums1[mid];
    }
};
