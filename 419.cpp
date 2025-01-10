class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int cnt = 0;
        // The though behind this approach is the fact that we know that
        // battleships can either be ONLY horizontal or ONLY vertical
        // With this, we know that at any given square, if we see that it
        // does not have an X above it or to the left of it, it is the start
        // to a battleship. We do not need to be concerned about whether or not'
        // it is part of a horizontal one or vertical one. That way, if we encounter
        // an X in the future in which there IS an X above it or to the left, the
        // battleship that is is apart of has already been counted and we're good
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'X' &&
                    (i == 0 || board[i - 1][j] != 'X') &&
                    (j == 0 || board[i][j - 1] != 'X')) {
                        cnt++;
                }
            }
        }

        return cnt;
    }
};
