class Solution {
public:
    bool isAnagram(string s, string t) {
        // Sort both string and compare O(n log n)
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        return s==t;
    }
};
