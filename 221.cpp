class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        int maxSide = 0;
        for(int i = 1; i < dp.size(); i++) {
            for(int j = 1; j < dp[0].size(); j++) {
                if(matrix[i - 1][j - 1] == '1') {
                    // set the dp[i][j] equal to min(topLeft, top, left) squares + 1
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }
        return maxSide * maxSide;
    }
};
