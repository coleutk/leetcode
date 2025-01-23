class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<pair<int, int>> seen;

        // Go through each row and count servers
        for(int i = 0; i < m; i++) {
            // Count the number of servers per row
            int cnt = 0;
            vector<pair<int, int>> rowPairs;
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    cnt++;
                    rowPairs.push_back({i, j});
                }
            }

            if(cnt >= 2) {
                // Add these index pairs to the set
                for(auto pair : rowPairs) {
                    seen.insert(pair);
                }
            }
        }

        // Go through each column and count servers
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            vector<pair<int, int>> colPairs;
            for(int j = 0; j < m; j++) {
                // Count the number of servers per column
                if(grid[j][i] == 1) {
                    cnt++;
                    colPairs.push_back({j, i});
                }
            }

            if(cnt >= 2) {
                for(auto pair : colPairs) {
                    seen.insert(pair);
                }
            }
        }

        return seen.size();
    }
};
