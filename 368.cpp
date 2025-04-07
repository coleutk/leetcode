class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1); // To track the indexes up to our current point

        // Tracks the greatest index of our current largest subset
        int maxi = 0;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                // Checks:
                // We have a valid divisibility
                // The length of the subset can be increased by including a previous number [j]
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    // Update current longest subset value at this index
                    dp[i] = dp[j] + 1;

                    // Track the previous index rather than the previous value
                    prev[i] = j;
                }
            }

            // We have found a larger subset as we've traversed the array,
            // so we can safely update this knowing that our index value will be
            // greater than before
            if(dp[i] > dp[maxi]) maxi = i;
        }

        // Iterate backwards starting from maxi, traversing back through our
        // prev array to backtrack all of our choices
        vector<int> res;
        for(int i = maxi; i >= 0; i = prev[i]) {
            res.push_back(nums[i]);
        }
        return res;
    }
};
