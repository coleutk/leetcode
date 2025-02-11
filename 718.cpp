class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Put each nums1 and nums2 on different axes of a matrix and run through it,
        // putting a one in a square where the values are the same, adding the value
        // in dp to the top left of it, because we need to keep the streak going because
        // if valid squares are diagonal to one another, we have a matching subarray

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 || j == 0) {
                    // We are on the outer edge, so we cannot look
                    // up and to the left
                    if(nums1[i] == nums2[j]) {
                        dp[i][j] = 1;
                    }
                } else {
                    // We are in bounds, only add the previous top left dp
                    // if the current elements are equal
                    if(nums1[i] == nums2[j]) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    }
                }
            }
        }

        int res = 0;
        for(auto vec : dp) {
            for(auto i : vec) {
                res = max(res, i);
            }
        }
        return res;
    }
};
