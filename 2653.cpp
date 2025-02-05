class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();

        // We need a vector to store frequencies starting from the lowest possible
        // value (-50)
        vector<int> freq(51, 0);

        vector<int> res;
        int j = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] < 0) freq[-nums[i]]++;
            if(i - j + 1 == k) {
                // We have a valid subarray

                // We also have all of the occurrences of negative numbers inside of this
                // subarray, so we can loop from the smallest possible one and add as we
                // find frequencies to ensure we are grabbing the smallest values
                int cnt = 0;
                for(int i = 50; i >= 1; i--) {
                    if(freq[i] > 0) {
                        cnt += freq[i];
                    }

                    if(cnt >= x) { 
                        res.push_back(-i);
                        break;
                    }
                }

                if(cnt < x) res.push_back(0);
                if(nums[j] < 0) freq[-nums[j]]--;
                j++;
            }
        }

        return res;
    }
};
