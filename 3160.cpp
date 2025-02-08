class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        unordered_map<int, int> ballToColor;
        unordered_map<int, int> colorFreq;
        vector<int> res(n);

        for(int i = 0; i < n; i++) {
            int ball = queries[i][0];
            int color = queries[i][1];

            // First, we need to check if ball has already been stored in ballToColor
            if(ballToColor.find(ball) != ballToColor.end()) {
                // We found the ball, so we must perform further checks
                // We are about to change the ball's color so we need to decrement that
                // color's frequency from colorFreq
                int colorToRemove = ballToColor[ball];
                colorFreq[colorToRemove]--;
                if(colorFreq[colorToRemove] == 0) colorFreq.erase(colorToRemove);
            }

            // Now, we need to update the ball's color in ballToColor
            ballToColor[ball] = color;
            colorFreq[color]++;

            // After we have performed all the necessary steps for that query, we can
            // safely add the size of colorFreq to our res
            res[i] = colorFreq.size();
        }

        return res;
    }
};
