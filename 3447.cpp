class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        // The approach here is to go through each group and see if its divisor(s)
        // are in elements, and if so, save the smallest index of its divisor, if it
        // appears in elements. First, we will need to pre-process a map of elements
        // mapping the element to its index in elements

        // For each groups[i], loop up to its square root and look at each divisor
            // For each divisor of that groups[i], check our elements map to see if
            // it exists. If it does, save it to a minimum variable

            // When done, save that minimum index variable in our answer for that group's idx

        unordered_map<int, int> elementIdx;
        for(int i = 0; i < elements.size(); i++) {
            // There may be duplicate elements, so skip it if we come across it again since
            // we already have the smallest index
            if(elementIdx.find(elements[i]) == elementIdx.end()) {
                elementIdx[elements[i]] = i;
            }
        }

        vector<int> res(groups.size());
        for(int i = 0; i < groups.size(); i++) {
            int minIdx = INT_MAX;

            // Go through its divisors
            for(int j = 1; j <= sqrt(groups[i]); j++) {
                if(groups[i] % j == 0) {
                    // Found j as a divisor, so find the corresponding one
                    int otherDivisor = groups[i] / j;

                    // Check elementIdx for both vals
                    if(elementIdx.count(j)) minIdx = min(minIdx, elementIdx[j]);
                    if(elementIdx.count(otherDivisor)) minIdx = min(minIdx, elementIdx[otherDivisor]);
                }
            }

            // Save the minIdx found to res
            if(minIdx == INT_MAX) {
                res[i] = -1;
            } else {
                res[i] = minIdx;
            }
        }

        return res;
    }
};
