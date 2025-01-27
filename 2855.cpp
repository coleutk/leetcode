class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        // Find the min value index

        // Iterate from the index of this min value and as long as the value after it
        // is greater than it, keep iterating
        
        // If we make it to the end, return n - index of min value, unless its already the first value
        int n = nums.size();
        int minVal = INT_MAX;
        int minValIdx = -1;
        for(int i = 0; i < n; i++) {
            if(nums[i] < minVal) {
                minVal = nums[i];
                minValIdx = i;
            }
        }

        int iterations = 0;
        int start = minValIdx;
        while(iterations < n - 1) {
            int curr = nums[start % n];
            int next = nums[(start + 1) % n];
            if(curr > next) {
                return -1;
            }
            start++;
            iterations++;
        }

        if(minValIdx == 0) return 0;
        return n - minValIdx;
    }
};
