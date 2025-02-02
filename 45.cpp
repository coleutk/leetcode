class Solution {
public:
    int dfs(int idx, vector<int> &nums, unordered_map<int, int> &memo) {
        // At each step of the recursion, we are computing and returning
        // how many jumps it takes to reach the last idx (n - 1) from idx
        
        // Base cases:

        // 1.) If we have computed this already for the current idx, just return
        // the # of jumps we calculated to reach the end from this idx
        if(memo.find(idx) != memo.end()) {
            // Memo is storing the minimum number of jumps to reach the end
            // from this idx
            return memo[idx];
        }

        // 2.) If we have reached the last index, 0 more jumps are needed
        if(idx == nums.size() - 1) {
            return 0;
        }

        // 3.) If we land on a 0, that means we are stuck and must return a
        // large number to represent an invalid path
        if(nums[idx] == 0) {
            return 1000000;
        }
        
        int minJumps = 1000000;
        int maxReach = idx + nums[idx]; // Maximum index we can reach from this position
        int furthestReach = min(maxReach, (int)nums.size() - 1); // Ensure you dont go out of bounds

        // Explore all possibilities from idx + 1 to the furthest index we can reach from this position
        for(int nextVisit = idx + 1; nextVisit <= furthestReach; nextVisit++) {
            // Recursively compute minimum jumps from this point to the end (n - 1)
            // We are taking the minimum results between all the dfs calls on the neighbors
            // to ensure we proceed with the best result so far
            minJumps = min(minJumps, 1 + dfs(nextVisit, nums, memo));
        }

        // Store the minimum out of these 3 and tie it to that index in the cache so we always
        // have it for future reference, avoiding repeated work
        memo[idx] = minJumps;
        return minJumps;
    }

    int jump(vector<int>& nums) {
        unordered_map<int, int> memo;
        // Start dfs with nums[0]
        return dfs(0, nums, memo);
    }
};
