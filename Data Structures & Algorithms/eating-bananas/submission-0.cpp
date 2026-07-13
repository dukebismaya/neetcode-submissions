class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;                                               
        int right = *std::max_element(piles.begin(), piles.end());
        int result{};
        while (left <= right) {
            int k = left + (right - left) / 2;
            long long curr_hour = 0;
            for (int pile : piles) {
                curr_hour += (pile - 1) / k + 1;
            }
            if (curr_hour <= h) {
                result = k;
                right = k - 1;
            } else {
                left = k + 1;
            }
        }
        return result;
    }
};