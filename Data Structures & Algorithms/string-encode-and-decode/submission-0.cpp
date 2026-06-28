class Solution {
   public:
    std::string encode(std::vector<std::string>& strs) {
        std::string encoded_str{};
        for (const auto& str : strs) {
            encoded_str += std::to_string(str.length()) + "#";
            encoded_str += str;
        }
        return encoded_str;
    }

    std::vector<std::string> decode(std::string& s) {
        std::vector<std::string> result;
        size_t i = 0;
        while (i < s.size()) {
            size_t j = i;
            while (j < s.size() && s.at(j) != '#') {
                j++;
            }
            int get_length{};
            for (size_t k = i; k<j; ++k){
                get_length = get_length * 10 + s.at(k)-'0';
            }

            result.emplace_back(s, j+1, get_length);
            i = j + 1 + get_length;
        }
        return result;
    }
};