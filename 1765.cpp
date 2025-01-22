class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        // Multisource BFS
        // We are essentially going to perform this BFS starting from multiple
        // water sources. This way, we can optimally derive the best height in all
        // directions while binding to the problem constraints
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> res(m, vector<int>(n, -1));
        set<pair<int, int>> seen;

        // We need to iterate through the isWater grid and add the coordinates of
        // all the water cells to a queue so we know to start with those first. We
        // will then add the children of each of the water cells, and proceeding
        queue<pair<int,int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(isWater[i][j] == 1) {
                    // We are on a water cell, add its coords to the q
                    q.push({i, j});
                    seen.insert({i, j});
                    res[i][j] = 0;
                }
            }
        }

        // Pop the current cell from the queue, and then add its neighbors to the queue
        // This way, we always prioritize the cells closest to the water sources
        while(!q.empty()) {
            pair<int, int> curr = q.front();
            int r = curr.first;
            int c = curr.second;
            int h = res[r][c];
            q.pop();

            vector<pair<int, int>> neighbors = {{r, c - 1}, {r, c + 1}, {r - 1, c}, {r + 1, c}};
            for(const auto &[r, c] : neighbors) {
                // Here, we are checking if the pair has been visited, but to optimize it more, 
                // instead of storing these in a set and checking for existence, we could just check
                // the res array to see if the height has been set. If it has not been set, it will
                // be -1 since thats what we initialized it as. So, we could just check if this value
                // is not -1
                if(r < 0 || r > m - 1 || c < 0 || c > n - 1 || seen.find({r, c}) != seen.end()) {
                    continue;
                }

                // We have a valid neighbor we haven't seen
                res[r][c] = h + 1;
                seen.insert({r, c});
                q.push({r, c});
            }
        }

        return res;
    }
};
