class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& safe) {
        // 0 will be false, 1 will be true
        if(safe[node] != -1) {
            return safe[node];
        }

        // Upon initially seeing the node, we will assume it is not safe
        safe[node] = 0;

        // Go through its neighbors to see if they lead to terminal nodes or they cycle
        for(int neigh : graph[node]) {
            if(dfs(neigh, graph, safe) == false) {
                // If ANY of its neighbors cycle, we can instantly conclude that the current
                // node is NOT a safe node. For it to be safe, ALL of its neighbors have to
                // end up leading to terminal nodes
                return false;
            }
        }

        // If you make it to this point, we have proven that all of a node's neighbors
        // DO NOT cycle, so its neighbors either are terminal nodes or they have neighbors
        // whose paths all lead to terminal nodes, so we can set it to true in the map and return true
        safe[node] = 1;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> res;
        vector<int> safe(n, -1);
        for(int i = 0; i < n; i++) {
            if(dfs(i, graph, safe)) {
                res.push_back(i);
            }
        }

        return res;
    }
};
