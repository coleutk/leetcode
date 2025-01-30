class Solution {
public:
    bool backtrack(vector<int>& matchsticks, int index, vector<int>& sides, int sideSize) {
        int n = matchsticks.size();
        if(index == n) {
            // If we have used all of the matchsticks, we need to check if all 4
            // sides are equal
            return (sides[0] == sideSize && sides[1] == sideSize && sides[2] == sideSize
            && sides[3] == sideSize);
        }

        // Try to add the current matchstick we are on (matchsticks[index]) to all
        // the sides starting from the first one
        for(int j = 0; j < 4; j++) {
            // Check if adding the current matchstick to the side is a valid choice
            if(sides[j] + matchsticks[index] <= sideSize) {
                // If it works, then do it
                sides[j] += matchsticks[index];

                // We found an option that works, so move to the next match in matchsticks
                // and also try to add it to a side, starting with sides[0]
                if(backtrack(matchsticks, index + 1, sides, sideSize)) return true;
                // Return true if it worked

                // If it did not work, then remove your most recent choice and try adding
                // it to a different side by continuining on through the loop
                sides[j] -= matchsticks[index];
            }

            // If we remove the last choice, and the side is left with a value of zero,
            // that means we essentially have a matchstick that will never fit into a side,
            // so we can instantly break here
            if(sides[j] == 0) break;
        }

        // If we make it all the way through the loop and no sides are valid to put the
        // match, we can return false for this series of choices
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        // First, we can do some checks to rule out the possibility of even being
        // able to make a square
        // 1) If there are less than 4 elements in the array
        // 2) The sum of the elements is not evenly divisible by 4
        
        // If these two have been passed, we know there is a possibility
        // So, we know the sum of what each group needs to be, so we can
        // start forming these groups

        int n = matchsticks.size();
        if(n < 4) return false;
        int total = 0;
        for(int match : matchsticks) total += match;

        if(total % 4 != 0) return false;
        int sideSize = total / 4;

        vector<int> sides(4, 0);

        // We need to create a backtracking function that explores all possibilities for sides
        return backtrack(matchsticks, 0, sides, sideSize);
    }
};
