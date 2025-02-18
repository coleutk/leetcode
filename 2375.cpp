class Solution {
public:
    bool backtrack(string pattern, string& curr, int patternIdx, unordered_set<int>& used) {
        // If we have formed a string curr that fills all the way out to size 9 then
        // we have found the best answer
        if(used.size() == pattern.size() + 1) {
            return true;
        }

        // We will run a loop from 1 to 9 so we can choose the best choice
        for(int i = 1; i <= 9; i++) {
            // Before even trying to make a choice, we need to see if we have already used the number
            if(used.find(i) != used.end()) continue;

            // Validate our choice
            if(pattern[patternIdx] == 'I') {
                // If we have an I, we know that our current choice must be greater than our last one
                if(i <= curr[patternIdx] - '0') {
                    continue;
                } else {
                    // We have found a valid choice for our current spot in pattern, make the choice
                    curr += to_string(i);
                    used.insert(i);
                    if(!backtrack(pattern, curr, patternIdx + 1, used)) {
                        // Our decision didn't work, so undo our choice and continue in the loop
                        // to try another choice
                        curr.pop_back();
                        used.erase(i);
                        continue;
                    } else {
                        return true;
                    }
                }
            } else {
                // If we have a D, we know that our current choice must be less than the last one
                if(i >= curr[patternIdx] - '0') {
                    continue;
                } else {
                    // We have found a valid choice for this blank in curr
                    curr += to_string(i);
                    used.insert(i);
                    if(!backtrack(pattern, curr, patternIdx + 1, used)) {
                        // Our choice led to a path that didn't work, so let's try another choice
                        curr.pop_back();
                        used.erase(i);
                        continue; // Continue through the loop to try the other numbers
                    } else {
                        return true;
                    }
                }
            }   
        }

        // Returning false essentially signals that we choice we made previously needs to be undone
        // We only want to do this if we have gone through the loop and proven that all possibilities
        // following that previous choice are ALL INVALID
        return false;
    }

    string smallestNumber(string pattern) {
        // Since the nums array is 1 longer than pattern, pattern is essentially
        // offset by 1 when comparing to the nums array. So, we will run a for loop
        // in the driver function that iterates through all the possible starting positions
        // represented by the _ below. That is the spot we will be starting backtracking with
        
        //   I I I D I D D D
        // _ 2 3 4 5 6 7 8 9
        unordered_set<int> used;
        string res = "ZZZZZZZZZZZZ";
        for(int i = 1; i <= 9; i++) {
            // Call dfs with a string already initialized with the first char being 1 <= 9
            string curr = to_string(i);
            used.insert(i);
            if(backtrack(pattern, curr, 0, used)) {
                res = min(res, curr);
                break;
            } // Success! return the string
            
            // If we make it here, the backtrack failed and we must pop back from curr to
            // try another starting point
            curr.pop_back();
            used.erase(i);
        }

        return res;
    }
};
