class Solution {
public:
    bool hasDuplicate(std::vector<int> &nums) {
    // Bruteforce O(n^2)
    /*for (auto num : nums) {
      if (std::count(nums.begin(), nums.end(), num) > 1)
        return true;
    }
    return false;*/

    // Sort the element O(n log n)
    // std::sort(nums.begin(), nums.end());
    // return std::adjacent_find(nums.begin(), nums.end()) != nums.end();

    // Using unordered set O(n)
    // std::unordered_set<int> seen;
    // for (auto num : nums) {
    //   if (seen.find(num) != seen.end())
    //     return true;
    //   seen.insert(num);
    // }
    // return false;

    std::unordered_map<int, int> num_map;
    for (const auto &num: nums){
      if (num_map.count(num)){
        return true;
      }
      num_map[num]++;
    }
    return false;
  }
};