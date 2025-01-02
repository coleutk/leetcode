class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int> postfixSum(n, 0); 

        // Create a postfix sum (starting from the back) to know how
        // many 1s come after a certain index in s. This way, as you
        // iterate forward through s, you can keep track of 0s and 
        // calculate a sum of 0s and 1s at any point
        int oneCnt = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '1') {
                oneCnt++; 
            } 
            
            postfixSum[i] = oneCnt; 
        } 

        int zeroCnt = 0;
        int mx = INT_MIN;
        for(int i = 0; i < s.size() - 1; i++) {
            if(s[i] == '0') {
                zeroCnt++;
            } 
        
            mx = max(mx, zeroCnt + postfixSum[i + 1]);
        }
        
        return mx;
    }
};
