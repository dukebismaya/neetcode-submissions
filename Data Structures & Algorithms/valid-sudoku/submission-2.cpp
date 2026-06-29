class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_map<int, unordered_set<char>> rows, cols;
        std::map<int, unordered_set<char>> square_grid;
        for (size_t r = 0; r < board.size(); ++r) {
            for (size_t c = 0; c < board[0].size(); ++c) {
                auto curr_el = board[r][c];
                if (curr_el == '.') continue;
                int get_cell_id = (r / 3) * 3 + (c / 3);
                if (rows[r].count(curr_el) || cols[c].count(curr_el) ||
                    square_grid[get_cell_id].count(curr_el))
                    return false;
                rows[r].insert(curr_el);
                cols[c].insert(curr_el);
                square_grid[get_cell_id].insert(curr_el);
            }
        }
        return true;
    }
};
