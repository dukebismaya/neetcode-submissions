class Solution {
   public:
    bool checkGrid(vector<vector<char>>& board, int start_row, int start_col) {
        std::unordered_map<char, int> check_freq;
        for (int i = start_row; i < start_row + 3; i++) {
            for (int j = start_col; j < start_col + 3; j++) {
                auto curr_el = board[i][j];
                if (curr_el == '.') continue;
                if (check_freq[curr_el] == 1) return false;
                check_freq[curr_el]++;
            }
        }
        return true;
    }
    bool checkRow(vector<vector<char>>& board, int row_id) {
        std::unordered_map<char, int> check_freq;
        for (int i = 0; i < board.size(); ++i) {
            auto curr_el = board[row_id][i];
            if (curr_el == '.') continue;
            if (check_freq[curr_el] == 1) return false;
            check_freq[curr_el]++;
        }
        return true;
    }
    bool checkCol(vector<vector<char>>& board, int col_id) {
        std::unordered_map<char, int> check_freq;
        for (int i = 0; i < board[0].size(); ++i) {
            auto curr_el = board[i][col_id];
            if (curr_el == '.') continue;
            if (check_freq[curr_el] == 1) return false;
            check_freq[curr_el]++;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); ++i) {
            if (!checkRow(board, i)) return false;
            if (!checkCol(board, i)) return false;
        }
        int i{0};
        while (i < board.size()) {
            int j{0};
            while (j < board[0].size()) {
                if (!checkGrid(board, i, j)) return false;
                j += 3;
            }
            i += 3;
        }
        return true;
    }
};
