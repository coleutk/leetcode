class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        // When dealing with these types of problems, break the problem down into
        // smaller pieces. For example, in order to reach the solution to this problem,
        // you need to find the answer to the question:

        // What gives two rows the ability to be the same?
        // 1. They already are the same
        // 2. They are direct inverses of one another
        // The problem isnt saying that one row has to be 1s and another row
        // has to also be 1s to be considered the same. All its saying is that
        // the values for these rows need to be uniform throughout. That is why
        // finding the inverse works also

        // REMEMBER:
        // If we are finding rows that meet the above criteria,
        // it does not matter how many columns we choose to flip for those rows,
        // we know that whatever amount it is, those rows can be made uniform by
        // some number of flips.

        unordered_map<string, int> patFreq;
        for(const auto &row : matrix) {
            // Construct the string key pattern for each row
            // The way we are doing this is that we are favoring strings that
            // start with a zero. So, if we encounter a row that starts with a zero,
            // we simply add that as a key. However, if it starts with a 1, we flip
            // all the bits and then add it, so it now starts with a zero
            string pattern = "";
            if(row[0] == 0) {
                for(int bit : row) {
                    pattern += to_string(bit);
                }
            } else {
                for(int bit : row) {
                    pattern += to_string(bit ^ 1);
                }
            }
            patFreq[pattern]++;
        }

        int mx = 0;
        for(const auto &pair : patFreq) {
            mx = max(mx, pair.second);
        }
        return mx;
    }
};
