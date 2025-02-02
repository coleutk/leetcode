class Solution {
public:
    void dfs(vector<int>& candidates, int idx, int target, int sum, vector<int> &path, vector<vector<int>> &res) {
        // Base case:
        // 1.) We hit the target exactly, we can add the path to our answer set
        if(sum == target) {
            res.push_back(path);
            return;
        }

        // 2.) We have exceeded the target threshold, return for backtracking
        if(sum > target) return;

        // Loop through all candidates starting with the current index
        for(int i = idx; i < candidates.size(); i++) {
            // If we encounter a duplicate element that came previous to the one we are
            // currently on, we can safely skip it because we have already considered the
            // element with all of the elements that come after it
            // For example, if we have [1, 1, 5, 4, 3]
            // We want to go ahead and skip the second 1 because all of the possible paths
            // that it can generate, have already been generated starting with the 1 right before it
            if(i > idx && candidates[i] == candidates[i - 1]) continue;

            path.push_back(candidates[i]);
            dfs(candidates, i + 1, target, sum + candidates[i], path, res);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Keep a set of answers to prevent duplicates
        vector<vector<int>> res;
        vector<int> path;
        
        // Run a dfs starting from every index in candidates
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target, 0, path, res);
        return res;
    }
};
