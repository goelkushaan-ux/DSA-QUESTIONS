class Solution {
public:
    bool check(vector<vector<char>>& board, int i, int j, string word,
               int count) {
        if (count == word.length())
            return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
            board[i][j] != word[count])
            return false;
        char temp = board[i][j];
        board[i][j] = 0;
        bool a = check(board, i, j + 1, word, count + 1) ||
                 check(board, i + 1, j, word, count + 1) ||
                 check(board, i - 1, j, word, count + 1) ||
                 check(board, i, j - 1, word, count + 1);
        board[i][j] = temp;
        return a;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (check(board, i, j, word, 0))
                    return true;
        return false;
    }
};