class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int curr = arr[0];
        int maxElement = arr[0];
        int streak = 0;

        queue<int> game;
        for(int i = 1; i < n; i++) {
            game.push(arr[i]);
            maxElement = max(maxElement, arr[i]);
        }

        while(streak < k) {
            // If we havent reached the streak at the point that we run into
            // the maxElement, we already know its going to win the game every
            // time, so go ahead and call it quits early
            if(curr == maxElement) return curr;

            int opponent = game.front();
            game.pop();

            if(curr > opponent) {
                streak++;
                game.push(opponent);
            } else {
                streak = 1;
                game.push(curr);
                curr = opponent;
            }
        }

        return curr;
        
    }
};
