class Solution {
public:
    int maximumSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<long long, vector<int>> mp;

        for(int &num : nums) {
            int temp = num;
            long long digSum = 0;
            while(temp) {
                digSum += temp % 10;
                temp /= 10;
            }

            mp[digSum].push_back(num);
        }

        // Iterate through. map and if there are more than 2 elements for that digSum,
        // take the last two in the set (being the greatest) and keep a running max
        int res = -1;
        for(const auto &pair : mp) {
            int n = pair.second.size();
            if(n >= 2) {
                res = max(res, pair.second[n - 1] + pair.second[n - 2]);
            }
        }
        return res;
    }
};
