class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int>products{};
        products.reserve(nums.size());
        for (size_t i=0; i<nums.size(); ++i){
            int j = nums.size()-1;
            int mult = 1;
            while(j>i){
                mult*=nums.at(j);
                j--;
            }
            int k = i-1;
            while (k>=0){
                mult*=nums.at(k);
                k--;
            }
            products.push_back(mult);
        }
        return products;
    }
};
