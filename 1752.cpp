class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        bool valid = false;
        for(int i = 0; i < n; i++) {
            // Start a loop from every index and see if we find a valid sorted path
            int start = i;
            int it = 0;
            while(it < n - 1) {
                if(nums[start % n] > nums[(start + 1) % n]) break;
                start++;
                it++;
            }

            if(it == n - 1) valid = true;
        }

        return valid;
    }
};
