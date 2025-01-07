class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        if(nums.size() <= 1) return 0;

        sort(nums.begin(), nums.end());
        int p1 = 0;
        int p2 = 1;
        int count = 0;

        // The key to this algorithm is that for each number starting from the lowest
        // one, we will "replace" it with the smallest number that is also greater than it
        // This way, we know that sorting is the right way to go. We will iterate through
        // the sorted array, greedily choosing the first number we see that is greater than
        // the current one we are looking at

        while(p2 < nums.size()) {
            if(nums[p2] > nums[p1]) {
                count++;
                p1++;
            }
            p2++;
        }

        return count;
    }
};
