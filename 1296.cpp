class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n % k != 0) return false;

        map<int, int> freq;
        for(int i : nums) {
            freq[i]++;
        }

        // We know that for every group we need k elements that are 1 apart from one another
        // So, after we have tracked the frequencies, we can iterate through the map and for each
        // value in there, we can iterate up from that value to the expected values that come after it
        // As we see/use the elements we need, we will decrement accordingly
        // If we make it all the way through the map, we know we can successfully make all the groups
        while(freq.size() != 0) {
            int val = freq.begin()->first;
            for(int i = val; i < val + k; i++) {
                if(freq[i] < 1) {
                    return false;
                }
                
                // If we found the element we need, take it out of the map
                freq[i]--;

                // As soon as a value's occurrences hit zero, that means we've used it up
                // so we do not want to try starting a group with it later. We can safely
                // stop considering it
                if(freq[i] == 0) {
                    freq.erase(i);
                }
            }
        }

        return true;
    }
};
