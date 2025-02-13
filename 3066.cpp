class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        unordered_map<long long, int> smaller;
        for(int num : nums) {
            if(num < k) {
                smaller[num]++;
            }
            minHeap.push(num);
        }

        // 1 2 3
        int cnt = 0;
        while(!smaller.empty()) {
            cnt++;

            // Pop the top two elements
            long long mn = minHeap.top();
            minHeap.pop();
            long long mx = minHeap.top();
            minHeap.pop();

            // Remove these two elements from smaller
            if(smaller.count(mn)) {
                smaller[mn]--;
                if(smaller[mn] == 0) smaller.erase(mn);
            }

            if(smaller.count(mx)) {
                smaller[mx]--;
                if(smaller[mx] == 0) smaller.erase(mx);
            }

            long long newVal = mn * 2 + mx;
            minHeap.push(newVal);

            if(newVal < k) smaller[newVal]++;
        }
        return cnt;
    }
};
