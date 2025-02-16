class Solution {
public:
    bool backtrack(vector<int>& res, int idx, unordered_set<int>& used, int n) {
        // Base Case: If we reach a point where idx is equal to res.size() - 1,
        // we have completely filled the res array, and we know that the first time
        // we hit this, it will be the best possible sequence because we are greedily
        // looping from the largest number at any point
        if(idx == res.size()) {
            return true;
        }

        // Greedily loop from the largest n value, always trying to insert the largest element into res
        for(int num = n; num >= 1; num--) {
        
            // 1. Validate Our Choice
            if(used.find(num) != used.end()) {
                continue;
            }
            // If our number is between 2 and n we must validate its placement and the position
            // We don't need to check if our starting index is valid because we will make sure of that
            // before actually making the recursive call so we just need to check that the other placement
            // of the number is valid. If not, we simply continue to the next num in the loop to try that
            if(num > 1 && (idx + num >= res.size() || res[idx + num] != -1)) {
                // cout << "Trying to put " << num << " at " << idx + num;
                // cout << " but there is a " << res[idx + num] << " there" << endl;
                // So if the index we need to place the number's counterpart at is either
                // out of bounds OR its in bounds but its already taken, its invalid so try next number
                continue;
            }

            // 2. Try Our Decision
            // If we made it here, that means we have found a valid placement for the number in the loop
            // So, lets actually place it and then set ourselves up for the next recursive call
            used.insert(num);
            res[idx] = num;
            if(num > 1) {
                res[idx + num] = num;
            }

            // Like mentioned at the top, we will need to do some work here to ensure that our next
            // starting placement will be valid to begin with (loop until we find unused index)
            int j = idx + 1; // Start it at the index right after the one we just started with
            while(j < res.size() && res[j] != -1) {
                j++;
            }

            // 3. Recursive Step
            // Now that we have found the next valid starting index, perform the recursion starting
            // from this spot
            // Return true if it works
            if(backtrack(res, j, used, n)) {
                return true;
            }

            // 4. Undo our bad choice :( [BACKTRACK]
            // IF WE MADE IT HERE this means that our recursive step resulted in a return false
            // So, we need to continue the loop and try perhaps a smaller num, maybe that will work
            // And if we finish through the whole loop and none of those worked, then we need to back it
            // up even further and undo our choice in the call previous to that
            // This will all take care of itself as long as we give it the recipe to undo at any given
            // point upon exhaustion of a possibility
            // We don't necessarily want to return false here, we just want to tell ourselves to undo
            // that choice and continue trying to find smaller numbers in the loop
            // We only want to return false IF we have explored all of the numbers in this loop. If we
            // have made it through the entire loop and none of the num placements worked, THEN that
            // is when we return false. We don't want to prematurely assume that all possible num
            // placements beyond a certain point are invalid. That will not work. ONLY after
            // we have PROVEN that nothing will work by exhausting the entire loop from a specific point
            // in the recursion tree is when we know for sure that we made a mistake in the previous call
            // and so then we need to explore other starting points from there

            // So here, we simply just undo our choice and look at the next num in the loop!
            used.erase(num);
            res[idx] = -1;
            if(num > 1) {
                res[idx + num] = -1;
            }
        }

        // IF WE REACH THIS POINT this is when we can return false because we have proven that all
        // possibilities following our most recent choice for the starting point DO NOT WORK, so our
        // only option is to say "hey, that starting point that we greedily chose unfortunately doesn't
        // work so we need to continue going through the loop in that recursive call and explore all
        // possibilities starting from the next best choice"
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        unordered_set<int> used;
        int size = 1 + ((n - 1) * 2); // Size of result array
        vector<int> res(size, -1);

        // Need to pass in:
        // &res to modify the answer
        // idx to know what index we are starting from
        // &used to keep track of what we've used
        // Don't need to pass in:
        // potential num values because we cycle through those during backtracking
        backtrack(res, 0, used, n);
        return res;
    }
};
