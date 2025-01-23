class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        // When I originally was coming up with the solution for this problem, I
        // was trying to find the exact number of local inversions and global inversions
        // and compare them to one another. Finding the number of global in O(n) was proving
        // to be difficult

        // Then you realize that ALL the problem is asking for is you to prove that the number
        // of global inversions is not equal to the number of local inversions. Once you realize this
        // you can conclude that you don't actually need to calculate the number of each. All you have
        // to do is develop some idea or proof that will tell you for sure if you're exceeding the local
        // inversion limit

        // Here is what I came up with:
        // Starting from the rightmost point in nums, if at any point, you see that there is MORE
        // than one element greater than the current element that COMES BEFORE IT, there will ALWAYS
        // be more global inversions than local

        // Proof:
        //  [0 3 1 2]:
        //  Take [3 1 2] for example. If you're considering only locals, you can see that in order to
        //  increment local, you must only consider the following neighbor element. In this case you see
        //  that 3 is greater than 1, but then you are forced to go to 1 and compare that to 2. 1 is less
        //  than 2, so we end with a final local inversion count of 1.
        //  However, now think about the global inversions. When considering the globals, you ARE NOT FORCED
        //  to compare the current element to the following neighbor and then move on. At any given element,
        //  you can compare it to ANY of the elements that come after it. See how you can compare 3 to both 1
        //  and 2? This obviously results in a global inversion count of 2, making it greater than the local
        //  count. This is how you can reach this proof. You notice that at ANY POINT in nums, if you have MORE
        //  THAN ONE ELEMENT that comes AFTER it that is LESS THAN it, you know that the global count will 
        //  ALWAYS be higher

        int n = nums.size();
        vector<int> maxSeen(n);
        maxSeen[0] = nums[0];
        for(int i = 1; i < n; i++) {
            maxSeen[i] = max(maxSeen[i - 1], nums[i]);
        }

        for(int i = n - 1; i >= 2; i--) {
            if(nums[i] < maxSeen[i - 2]) return false;
        }

        return true;
    }
};
