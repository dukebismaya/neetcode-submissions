class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows = board.size(), cols = board[0].size();
        if (rows != 9 && cols != 9) return false;

        for (int i = 0; i < rows; ++i) {
            std::unordered_set<char> seen;
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == '.') continue;
                if (seen.count(board[i][j])) return false;
                seen.insert(board[i][j]);
            }
        }
        for (int i = 0; i < cols; ++i) {
            std::unordered_set<char> seen;
            for (int j = 0; j < rows; ++j) {
                if (board[j][i] == '.') continue;
                if (seen.count(board[j][i])) return false;
                seen.insert(board[j][i]);
            }
        }
        int i{0};
        while (i < rows) {
            int c{0};
            while (c < cols) {
                std::unordered_set<char> seen;
                for (int j = i; j < i + 3; ++j) {
                    for (int k = c; k < c + 3; ++k) {
                        if (board[j][k] == '.') continue;
                        if (seen.count(board[j][k])) return false;
                        seen.insert(board[j][k]);
                    }
                }
                c += 3;
            }
            i += 3;
        }
        return true;
    }
};