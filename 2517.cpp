class Solution {
public:
    bool valid(vector<int>& price, int k, int minDiff) {
        // Sort of take a greedy approach here by always prioritizing the
        // smallest possible candy SUCH THAT we achieve this minimum difference
        int lastPicked = price[0];
        int count = 1;
        for(int i = 1; i < price.size(); i++) {
            if(price[i] - lastPicked >= minDiff) {
                lastPicked = price[i];
                count++;
            }
            if(count == k) return true;
        }
        return false;
    }

    int maximumTastiness(vector<int>& price, int k) {
        // We want to run binary search on the answer to see if we can find a group
        // with the LARGEST MINIMUM DIFFERENCE BETWEEN ALL ELEMENTS
        // We will use binary search to try and maximize this value as our answer
        sort(price.begin(), price.end());

        // We will define a function that will run through sorted prices and determine
        // if we can form a group of size k with a minimum difference of n
        int start = 0;
        int end = INT_MAX;
        int res = 0;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(valid(price, k, mid)) {
                // We have found a valid minDifference that works, so we can try
                // to look for a bigger one
                res = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return res;
    }
};
