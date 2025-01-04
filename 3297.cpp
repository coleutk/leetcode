class Solution {
public:
    bool isValid(vector<int> prefix, vector<int> count) {
        for(int i = 0; i < 26; i++) {
            if(prefix[i] < count[i]) {
                return false; // Not enough characters in current prefix 
            } 
        } 
        return true;
    }

    long long validSubstringCount(string word1, string word2) {
        // Create a count of the character frequency in word2
        vector<int> count(26, 0);
        for(int i = 0; i < word2.size(); i++) {
            count[word2[i] - 'a']++; 
        }

        int n = word1.size();
        long long res = 0;
        int i = 0;
        int j = 0;
        vector<int> prefix(26, 0);

        while(i < n) {
            prefix[word1[i] - 'a']++; 

            // Key: When we find a current substring that is valid, we know that
            // all of the substrings formed by extending the current substring
            // window to include the remaining 'n - i' characters are also valid

            // This is a while loop because when we have found a valid window,
            // we will try to shrink the window from the left bound and grab
            // as many valid substrings as we can without having to move right yet
            while(isValid(prefix, count)) {
                res += n - i; // Super crucial
                prefix[word1[j] - 'a']--;   
                j++;
            }

            i++;
        } 

        return res;
    }
};
