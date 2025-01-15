class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> start;
        vector<int> end;
        for(int i = 0; i < intervals.size(); i++) {
            start.push_back(intervals[i][0]);
            end.push_back(intervals[i][1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int p1 = 0; // Start vector iterator
        int p2 = 0; // End vector iterator
        int currGroups = 0;
        int res = 0;
        while(p1 < start.size()) {
            if(start[p1] <= end[p2]) {
                currGroups++;
                p1++;
            } else {
                currGroups--;
                p2++;
            }

            res = max(res, currGroups);
        }

        return res;
    }
};
