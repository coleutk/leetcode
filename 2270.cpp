class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        if(nums.size() == 2) {
            if(nums[0] >= nums[1]) return 1; 
        }
        
        int n = nums.size();
        vector<long long> prefixSum(n, 0);
        vector<long long> suffixSum(n, 0);

        // Create a prefix sum of all of the elements
        long long currSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            prefixSum[i] = currSum; 
        }

        // Create suffix sum of all of the elements
        currSum = 0;
        for(int i = n - 1; i >= 0; i--) {
            currSum += nums[i]; 
            suffixSum[i] = currSum;
        }
        
        // Run through the the size of the original arrays and compare the
        // current element (being the prefix sum up to that point) with the
        // element immediately after (being the suffix sum of all the elements
        // after that) to determine if it is a valid split
        int res = 0;
        for(int i = 0; i < n - 1; i++) {
            if(prefixSum[i] >= suffixSum[i + 1]) res++; 
        }

        return res;
    }
};
