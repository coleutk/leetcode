class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        for(auto query : queries) {
            int k = query[0];
            int trim = query[1];

            // Go through nums and apply each trim, adding it to a pair with its idx in nums
            int n = nums[0].size();
            vector<pair<string, int>> pairs;
            for(int i = 0; i < nums.size(); i++) {
                string numTrim = nums[i].substr(n - trim);
                pairs.push_back({numTrim, i}); // [numTrim, original idx]
            }

            // Instead of converting the trimmed num to an integer, we have just saved
            // it as a string. This still works because when we sort, it will still sort
            // by lexicographically smallest number, as smaller numbers have a smaller
            // ASCII
            sort(pairs.begin(), pairs.end());
            res.push_back(pairs[k - 1].second);
        }
        return res;
    }
};
