class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        // Create a cache that maps a string version of the current needs array to
        // the minimum cost found up to this point for that needs array. Our path to
        // get to this point, whatever it may be, simply does not matter. All we need
        // to take into account here is the fact that we have already found what the
        // minimum cost is for this exact needs array upon arrival, so we can return that
        // and avoid needless traversal
        unordered_map<string, int> memo;
        return dfs(price, special, needs, memo);
    }

    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, 
    unordered_map<string, int> &memo) {
        // Convert the current needs array to a string so we can check the cache for it
        string key = serialize(needs);
        if(memo.find(key) != memo.end()) {
            return memo[key];
        }
        
        int n = price.size();

        // At the beginning of each call, we need to see how much it would cost us to fulfill
        // our current needs by just using the price array as a baseline
        int directCost = 0;
        for(int i = 0; i < n; i++) {
            directCost += price[i] * needs[i];
        }

        // Assume that the minCost IS the direct cost in the event that there are no special offers
        // OR in the event that no special offers may yield a better minCost
        int minCost = directCost;

        // Take our current needs array and explore all potential special offers from this point on
        for(auto offer : special) {
            bool validOffer = true;
            vector<int> newNeeds(needs);
            for(int i = 0; i < n; i++) {

                // Subtract the values from the special offer simulating us actually trying to take it
                newNeeds[i] -= offer[i];

                // See if we took too much, making it an invalid choice
                if(newNeeds[i] < 0) {
                    validOffer = false;
                    break;
                }
            }

            // If we made it to this point and validOffer is true, we have another path we can explore
            if(validOffer) {
                // Update minCost with the minCost we grab from exploring this path
                // Note: easily grab the price of taking that special offer with offer[n]
                //       We have to include this because we are simulating the scenario in which
                //       we actually "took" that offer. Every choice that comes after that uses that info
                // We are also passing in the updated version of needs to the new call, since taking the
                // offer affected its values
                minCost = min(minCost, offer[n] + dfs(price, special, newNeeds, memo));
            }
        }

        memo[key] = minCost;
        return minCost;
    }

    string serialize(vector<int> &needs) {
        string needsStr = "";
        for(int num : needs) {
            needsStr += to_string(num) + ",";
        }
        return needsStr;
    }
};
