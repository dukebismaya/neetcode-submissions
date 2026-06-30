class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int seen[5005] {0};
        for (int i=0; i<numbers.size(); ++i){
            int complement = target-numbers[i];
            if (complement<=3000 && complement>=-2000){
                if (seen[complement+2000]!=0)
                    return {seen[complement+2000], i+1};
            }
            seen[numbers[i] + 2000] = i + 1;
        }
        return {};
    }
};
