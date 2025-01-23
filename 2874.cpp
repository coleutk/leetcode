class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        // The idea here is that you want to find the maximum element to the left and
        // to the right of any given element in nums within [1, n - 1] because given the
        // equation, you know this method will yield the maximum result
        // So, you can make prefix and suffix arrays that store the maximum values seen
        // so far iterating from both sides of the array. At any given point in nums,
        // calulate the result based on the maximum seen up to that point from both sides
        int n = nums.size();
        vector<int> maxSeenLeft(n);
        maxSeenLeft[0] = nums[0];

        vector<int> maxSeenRight(n);
        maxSeenRight[n - 1] = nums[n - 1];

        for(int i = 1; i < n; i++) {
            maxSeenLeft[i] = max(maxSeenLeft[i - 1], nums[i]);
        }

        for(int i = n - 2; i >= 0; i--) {
            maxSeenRight[i] = max(maxSeenRight[i + 1], nums[i]);
        }

        long long res = 0;
        for(int i = 1; i < n - 1; i++) {
            long long curr = (long long)(maxSeenLeft[i - 1] - nums[i]) * maxSeenRight[i + 1];
            res = max(res, curr);
        }

        return res;
    }
};
