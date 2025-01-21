class Solution {
public:
    bool isValid(int mid, vector<int> &nums, int p) {
        int n = nums.size();
        int i = 0;
        int cnt = 0;
        while(i < n - 1) {
            if(abs(nums[i] - nums[i + 1]) <= mid) {
                cnt++;
                i += 2;
            } else {
                i += 1;
            }
            
            if(cnt >= p) return true;
        }
        return false;
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        // The optimal approach here is not so intuitive, but it makes sense
        // The reason it is not intuitive is because we will not actually be
        // performing binary search on the array, but on the maximum possible
        // difference between pairs, being 10^9. The reason this works is because
        // At every halfing of that difference, we can linearly search the
        // original array to see if we have 'p' pairs that have a maximum difference
        // less than or equal to that number. For example, if we find that we do have
        // 'p' pairs that have a maximum difference <= 10^9, then we save that as our
        // minimum maximum difference found so far, we half 10^9, and then search if we
        // can find 'p' pairs that have a maximum difference of less than 10^9/2

        // The way we will be implementing a greedy approach here is by sorting the original
        // array, so that we know that whatever pair we choose, we will always be choosing an
        // optimal choice by comparing the current element to its neighbor. However, we cannot
        // include the same index in more than one pair, so we have to be careful about how we
        // iterate through the array. We will take this approach:
        // 1. If we find that the abs difference between the current element and the one after it
        //  meet the criteria (maximum difference being less than the arbitrary number passed in),
        //  then we know to take that pair and add to our count. BUT, we have to move the pointer
        //  forward two spaces so we make sure we don't consider the index that we already chose
        //  to be the start of the next pair
        // 2. If we find that the abs difference between the current element and the one after is
        //  larger than the maximum difference we are looking for, we are safe to not use this pair
        //  and move the pointer forwards only 1 space. This way, we will be safely considering each
        //  pair, not having to worry about re-using indexes
        // We will use a helper function called isValid to implement this methodic approach

        if(p == 0) return 0;

        sort(nums.begin(), nums.end());
        int left = 0;
        long long right = 10e9;
        int res = INT_MAX;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(isValid(mid, nums, p)) {
                // If we have found 'p' pairs that have a maximum difference of less than mid,
                // we can continue to search the original array to potentially find 'p' pairs
                // that yield an even smaller maximum difference
                res = mid; // Update res just in case we cannot find a smaller max difference
                right = mid - 1;
            } else {
                // If we find that we have cut the maximum difference too small and we cannot find
                // 'p' pairs to meet this criteria, we will have to try our luck with a larger maximum
                // difference
                left = mid + 1;
            }
        }
        return res;
    }
};
