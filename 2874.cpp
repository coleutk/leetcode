// Old Solution
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

// New Solution:
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long prefix_max = nums[0];
        long long max_diff = 0;
        long long res = 0;
        for(int k = 1; k < nums.size(); k++) {
            long long curr = nums[k];

            // We can keep updating prefix_max to find a larger max_diff, but we won't actually
            // update max_diff until we find a better complement to our new prefix_max. Thus, as
            // we search through the array, we are using our best max diff so far (calculated using
            // the previous largest prefix max) to continue making calculations until we find
            // this new larger prefix max's complement
            res = max(res, max_diff * curr);
            prefix_max = max(prefix_max, curr);
            max_diff = max(max_diff, prefix_max - curr);
        }

        return res;
    }
};
