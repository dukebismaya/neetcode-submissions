class Solution {
public:
    bool isAnagram(string s, string t) {
        // Count frequencies
    if (s.length() != t.length())
      return false;
    std::unordered_map<char, int> charS;
    std::unordered_map<char, int> charT;
    for (size_t i = 0; i < s.length(); ++i) {
      charS[s.at(i)] += 1;
    }
    for (size_t i = 0; i < t.length(); ++i) {
      charT[t.at(i)] += 1;
    }
    return charS == charT;
        
    }
};
