class Solution {
public:
    void dfs(unordered_set<string>& res, unordered_set<int> &visited, string tiles, string curr) {
        // If we form a string that reaches the size of tiles, add it to res
        if(curr.size() == tiles.size()) {
            res.insert(curr);
            return;
        }

        // Loop from A->C
        // Pass in the starting index of our string to the dfs
        // Keep a set of indices we have visited for the current exploration
        for(int i = 0; i < tiles.size(); i++) {
            // Call dfs with the current state of your string
            // Check if we have already used the current index
            if(visited.find(i) != visited.end()) continue;
            curr += tiles[i];
            visited.insert(i);

            dfs(res, visited, tiles, curr);
            // We have to undo our letter choice after returning
            curr.pop_back();
            visited.erase(i);
        }

        // If we run out of scope, we just need to add the leftover curr to res
        if(!curr.empty()) res.insert(curr);
    }

    int numTilePossibilities(string tiles) {
        unordered_set<string> res;
        unordered_set<int> visited;

        dfs(res, visited, tiles, "");

        // for(auto s : res) {
        //     cout << s << endl;
        // }

        return res.size();
    }
};
