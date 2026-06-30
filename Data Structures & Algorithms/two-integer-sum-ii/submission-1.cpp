class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left {};
        int right = numbers.size()-1;
        while (left<right){
            int get_sum = numbers[left]+numbers[right];
            if (get_sum==target) return {left+1, right+1};
            else if (get_sum<target) left++;
            else right--;
        }
        return {};
    }
};
