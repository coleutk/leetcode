class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<int>> groups; // [% result, list of nums with that % result]

        for(int num : nums) {
            groups[num % space].push_back(num);
        }
        
        // Go through the map to find the biggest group size
        // If there is a tie, take the minimum of each num
        int res = INT_MAX;
        int maxSize = 0;
        for(const auto &pair : groups) {
            if(pair.second.size() == maxSize) {
                res = min(res, pair.second[0]);
            } else if(pair.second.size() > maxSize) {
                maxSize = pair.second.size();
                res = pair.second[0];
            } 
        }

        return res;
    }
};
