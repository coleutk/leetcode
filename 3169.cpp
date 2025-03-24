class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(), meetings.end());
        int prevEnd = 0;
        for(int i = 0; i < n; i++) {
            int start = max(meetings[i][0], prevEnd + 1);
            int end = meetings[i][1];
            int len = end - start + 1;
            days -= max(0, len);
            prevEnd = max(prevEnd, end);
        }
        return days;
    }
};
