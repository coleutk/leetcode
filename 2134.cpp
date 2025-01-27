class Solution {
public:
    int minSwaps(vector<int>& nums) {
        // The idea behind the solution to this problem is to count the total number of 1s
        // By doing this, we know that it is our goal to have a contiguous subarray of 1s
        // of length (amount of ones in the array). That is what we need to create in order
        // to solve this problem. Now, the most optimal way to form this subarray of # of
        // desired 1s is to give ourselves the best starting point. What I mean by this is,
        // find a subarray that already exists in the array of size desired 1s and see which
        // subarray already contains the most amount of 1s in that range. That way, we know that
        // we are going to find the best starting point to create the desired 1s subarray. Once
        // we have found the subarray of that size containing the most 1s, all we have to do is
        // "move" or "swap" the 1s outside of that window into the window

        // However, it can be a little tricky given the fact that 1s can be contigious in a
        // circular manner, so iterating through and obtaining this max subarray of 1s needs
        // to wrap around the array

        // You can either concatenate the array to itself in order to simulate traversing it wrapped
        // around itself in O(n) space, OR you can just % logic to "pretend" you are iterating through
        // this "concantenated" array to reach the same solution
        int n = nums.size();
        int totalOnes = 0;
        for(int num : nums) {
            if(num == 1) totalOnes++;
        }

        int left = 0;
        int windowOnes = 0;
        int maxWindowOnes = 0;
        for(int right = 0; right < n * 2; right++) {
            if(nums[right % n] == 1) {
                windowOnes++;
            }
            
            if(right >= totalOnes) {
                // We have reached the max size of our window, so we need to
                // increment our left pointer to stay within bounds
                windowOnes -= nums[left % n]; // Subtract 1 if losing a 1, subtracting 0 does nothing
                left++;
            }

            maxWindowOnes = max(maxWindowOnes, windowOnes);
        }

        return totalOnes - maxWindowOnes;
    }
};
