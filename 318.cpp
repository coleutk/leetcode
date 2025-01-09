class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        
        // We want to run through the words array and create a bitmask representation
        // of the alphabet for each word. If a character is present, we will flip the bit
        // for that character. This way, we will easily be able to make comparisons later
        vector<int> bitmasks(n, 0);

        // We also need to save the word lengths for access later
        vector<int> lengths(n, 0);

        for(int i = 0; i < n; i++) {
            for(char c : words[i]) {
                // OR the mask for this word left shifted by the respective amount to
                // represent its occurrence
                bitmasks[i] |= (1 << (c - 'a'));
            }
            lengths[i] = words[i].size();
        }
        
        int longest = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j) {
                    if((bitmasks[i] & bitmasks[j]) == 0) {
                        longest = max(longest, lengths[i] * lengths[j]);
                    }
                }
            }
        }

        return longest;
    }
};
