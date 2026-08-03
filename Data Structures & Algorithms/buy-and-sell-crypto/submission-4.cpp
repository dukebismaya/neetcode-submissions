class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int left{}, right{1}, maxProfit{};
        while (right < prices.size()) {
            if (prices[left] < prices[right]) {
                maxProfit = std::max(maxProfit, prices[right] - prices[left]);
            } else
                left = right;
            right++;
        }
        return maxProfit;
    }
};
