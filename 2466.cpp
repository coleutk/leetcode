class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int mod = 1e9 + 7;
        unordered_map<int, int> memo;
        return dfs(low, high, zero, one, 0, memo, mod);
    }

    int dfs(int low, int high, int zero, int one, int length, unordered_map<int, int> &memo, 
    const int mod) {
        if(memo.find(length) != memo.end()) {
            return memo[length];
        }
        
        // If the string has reached a length too high, terminate this path 
        if(length > high) {
            return 0;
        }

        // Count this string if its within the valid range
        int count = 0;
        if(length >= low) {
            count++;
        }

        // Explore adding 'zero' characters
        count = (count + dfs(low, high, zero, one, length + zero, memo, mod)) % mod;

        // Explore adding 'one' characters
        count = (count + dfs(low, high, zero, one, length + one, memo, mod)) % mod;

        memo[length] = count;
        return count;
    }
};
