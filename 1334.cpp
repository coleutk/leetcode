class Solution {
public:
    int dijkstra(int node, vector<vector<pair<int, int>>> adj, int distanceThreshold) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, node}); // Push the current distance of the starting node to itself
        unordered_set<int> visited;

        // Pop from the heap to potentially find valid neighboring cities
        while(!minHeap.empty()) { // minHeap pair: [dist, node]
            pair<int, int> curr = minHeap.top();
            minHeap.pop();

            int dist1 = curr.first;
            int node1 = curr.second;

            // If we encounter a node we have already visited, we don't want to count it twice, skip
            if(visited.find(node1) != visited.end()) continue;
    
            // If we are going to process the node, let's add it to visited so we don't revisit it
            visited.insert(node1);

            // Traverse the current node's neighbors to see if the sum of distances is valid
            for(auto neigh : adj[node1]) {
                int dist2 = neigh.second;
                int node2 = neigh.first;

                if(dist1 + dist2 <= distanceThreshold) {
                    minHeap.push({dist1 + dist2, node2});
                }
            }
        }
        
        return visited.size() - 1;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Construct the bidirectional adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i < edges.size(); i++) {
            int from = edges[i][0];
            int to = edges[i][1];
            int weight = edges[i][2];

            // Only add the edge if its <= distanceThreshold
            if(weight <= distanceThreshold) {
                adj[from].push_back({to, weight});
                adj[to].push_back({from, weight});
            }
        }

        // for(int i = 0; i < n; i++) {
        //     cout << i << ": ";
        //     for(auto pair : adj[i]) {
        //         cout << "[" << pair.first << ", " << pair.second << "]" << " ";
        //     }
        //     cout << endl;
        // }

        int res = -1;
        int minCount = n; // Worst answer is that we have one city connected to all other cities
        // We are going to run a modified dijkstra's starting from each source node, keeping
        // track of the distance starting from each node
        for(int i = 0; i < n; i++) {
            int count = dijkstra(i, adj, distanceThreshold);
            cout << i << ": " << count << endl;
            if(count <= minCount) {
                minCount = count;
                res = i;
            }
        }

        return res;
    }
};
