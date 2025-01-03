class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = queries.size();
        int m = words.size();
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        vector<int> prefixSum(m, 0); 
        
        // Create a prefix sum of the amount of words that fit the problem
        // constraint (start and end with vowel)
        int validCnt = 0;
        for(int i = 0; i < words.size(); i++) {
           int start = 0;
           int end = words[i].size() - 1;

           if(vowels.find(words[i][start]) != vowels.end()) {
                if(vowels.find(words[i][end]) != vowels.end()) {
                    validCnt++; 
                }  
           } 
        
           prefixSum[i] = validCnt;
        }

        vector<int> res(n, 0);
        for(int i = 0; i < n; i++) {
            int left = queries[i][0];
            int right = queries[i][1]; 

            // Use the formula: prefixSum[right] - prefixSum[left - 1] to calculate
            // the amount of valid words within that window. If left is equal to zero,
            // then just take the prefixSum[right]
            int sum = 0;
            if(left != 0) {
                left--;
                sum = prefixSum[right] - prefixSum[left];
            } else {
                sum = prefixSum[right]; 
            }

            res[i] = sum; 
        }
        
        return res;
    }
};
