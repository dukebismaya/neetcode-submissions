class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int start = 0;
        int end = start+1;
        int curr_profit = 0;
        while (start<prices.size()-1){
            curr_profit = std::max(curr_profit, prices[end]-prices[start]);
            end++;
            if (end>=prices.size()){
                start++;
                end = start+1;
            }
        }

        return curr_profit;
    }
};
