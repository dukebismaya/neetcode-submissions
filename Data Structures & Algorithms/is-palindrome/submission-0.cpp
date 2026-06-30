class Solution {
public:
    bool isPalindrome(string s) {
        std::deque<char>d;
        for (const auto &c: s){
            if (std::isalnum(c))
                d.push_back(std::tolower(c));
        }
        char begin_el{}, end_el{};
        while(d.size()>1){
            begin_el = d.front();
            end_el = d.back();
            if(begin_el!=end_el)
                return false;
            d.pop_back();
            d.pop_front();
        }
        return true;
    }
};
