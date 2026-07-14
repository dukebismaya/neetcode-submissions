class TimeMap {
    unordered_map<string, vector<pair<int, string>>> m;

   public:
    TimeMap() {}

    void set(string key, string value, int timestamp) { 
        m[key].push_back({timestamp, value}); 
    }

    string get(string key, int timestamp) {
        const auto& vals = m[key];
        int left = 0;
        int right = vals.size() - 1;
        string res = "";
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (vals[mid].first <= timestamp) {
                res = vals[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return res;
    }
};
