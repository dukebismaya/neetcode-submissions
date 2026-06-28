class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int num_len = nums.size();
        std::vector<int>products(num_len, 1);

        int prod_from_left = 1;
        for (int i=0; i<num_len; i++){
            products[i]=prod_from_left;
            prod_from_left *= nums[i];
        }
        int prod_from_right = 1;
        for (int i=num_len-1; i>=0; --i){
            products[i] *= prod_from_right;
            prod_from_right *= nums[i];
        }
        
        return products;
    }
};
