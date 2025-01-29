class Solution {
public:
    int dfs(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited) {
        int m = grid.size();
        int n = grid[0].size();

        // 1) Check boundaries first
        if(i < 0 || i > m - 1 || j < 0 || j > n - 1) return 0;

        // 2) If cell has no fish, return 0, as the path stops here
        if(grid[i][j] == 0) return 0;

        // 3) If the cell has already been visited, we don't want to visit it again
        if (visited[i][j] == true) return 0;

        // 4) If it hasn't been visited before, it has now, so mark it as true
        visited[i][j] = true;

        // Notice how we needed to do all boundary checks to ensure we have a valid
        // i and j before accessing the grid. When you're writing these functions,
        // make sure that you have crossed off all checkboxes before jumping into
        // calculations. Also, make sure things are set in the order you need.
        int sum = grid[i][j];
        sum += dfs(grid, i - 1, j, visited); // Up
        sum += dfs(grid, i + 1, j, visited); // Down
        sum += dfs(grid, i, j - 1, visited); // Left
        sum += dfs(grid, i, j + 1, visited); // Right

        return sum;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        // Run a dfs search starting from all nonzero cells
        // Keep a visited array so we don't re-search cells that have been visited
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int res = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // Check if cell has been visited
                // and for if it is a nonzero cell
                if(grid[i][j] != 0 && visited[i][j] != true) {
                    res = max(res, dfs(grid, i, j, visited));
                }
            }
        }

        return res;
    }
};
