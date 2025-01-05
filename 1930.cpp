class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<string> res;
        unordered_set<char> left;
        unordered_map<char, int> right;

        // Fill up the right side with all the characters in s
        for(int i = 0; i < s.size(); i++) {
            right[s[i]]++;
        }

        // Iterate through s and perform checks, adding to left and
        // decrementing to right as you proceed
        for(int i = 0; i < s.size(); i++) {
            // When we are looking at a character, we cannot consider it as a
            // part of the right side anymore because the whole point is to consider
            // the current character as a potential middle character for the palindrome
            // So, we must decrement it here before we simulate anything further
            // The reason why we have to do it here is because we have already filled
            // the right side up, ASSUMING that the current character IS part of the right
            // side. But, as previously mentioned, this is not the case since we are
            // looking at it right now
            right[s[i]]--;

            // Iterate through set to see if map contains the same char
            for(char currChar : left) {
                if(right[currChar] > 0) {
                    // Character appeared in the map at least 1 time
                    string palindrome = "";
                    palindrome += currChar;
                    palindrome += s[i];
                    res.insert(palindrome);

                }
            }

            // However, we can wait until we are down here to add it to the left because
            // we never assumed that the current character was a part of the left at any
            // point. But once we are done with it, we know we can for sure add it to left
            left.insert(s[i]);
        }

        return res.size();
    }
};
