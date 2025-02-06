class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> productFreq;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int product = nums[i] * nums[j];
                productFreq[product]++;
            }
        }

        int res = 0;
        for(const auto &pair : productFreq) {
            // 4 unique products makes 6 pairs
            // 3 unique products makes 3 pairs
            // (4 unique products * 3 unique products) / 2 = total amount of pairs at 4
            // then multiply this number of pairs by 8 to see how many tuples it generates
            int pairs = pair.second * (pair.second - 1) / 2;
            res += pairs * 8;
        }

        return res;
    }
};
