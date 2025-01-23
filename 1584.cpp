class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // We need to create an adjacency list:
        //  The index will represent the index of the pair in points that will be the source
        //  The pairs stored in a vector at that index will be:
        //  [manhattan distance from source index, index of point we are connecting to]
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j = i + 1; j < n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int manDist = abs(x1 - x2) + abs(y1 - y2);
                adj[i].push_back({manDist, j});
                adj[j].push_back({manDist, i}); // Don't forget to include the outgoing edge from j too
            }
        }

        // Prim's algorithm
        int totalCost = 0;
        unordered_set<int> visited; // This will store the indexes of the pairs to see if we have connected it
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, 0}); // The manhattan distance from the first pair to itself is 0
        while(visited.size() < n) {
            pair<int, int> top = minHeap.top();
            minHeap.pop();

            // Grab the values
            int manDist = top.first;
            int pairIdx = top.second;

            // Check if we have already visited the index
            if(visited.find(pairIdx) != visited.end()) continue;

            totalCost += manDist;
            visited.insert(pairIdx);

            for(const auto &pair : adj[pairIdx]) {
                int neiManDist = pair.first;
                int neiPairIdx = pair.second;
                if(visited.find(neiPairIdx) == visited.end()) {
                    minHeap.push(pair);
                }
            }
        }
        return totalCost;

        // Side note: If you come back to this problem and are struggling to understand it,
        // draw out the entire adjacency list and step through the code, keeping track of
        // visited, totalCost, minHeap, and the values popped from minHeap
    }
};
