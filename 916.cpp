class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        // Map out the frequencies from words2
        unordered_map<char, int> needMaxes;
        for(string word : words2) {
            unordered_map<char, int> currNeed;
            for(char c : word) {
                currNeed[c]++;
            }

            // Go through currNeed
            // 1. If needMaxes does not have the letter occurence, add it to the map
            // 2. If needMaxes does have it, update the max occurrences with the occurrence in currNeed
            for(const auto &pair : currNeed) {
                // This line of code works because if it doesnt exist, it enters
                // it into the map with pair.first as the key and max(0, pair.second)
                // as the value
                needMaxes[pair.first] = max(needMaxes[pair.first], pair.second);
            }
        }

        vector<string> res;
        for(string word : words1) {
            // Map out the frequencies from word1
            unordered_map<char, int> have;
            for(char c : word) {
                have[c]++;
            }

            // Go through needMaxes and see if we have what we need
            bool valid = true;
            for(const auto &pair : needMaxes) {
                if(have.find(pair.first) != have.end()) {
                    // Now that we know it has it, we need to make sure it has at least what we need
                    if(have[pair.first] < pair.second) {
                        valid = false;
                        break;
                    }
                } else {
                    valid = false;
                    break;
                }
            }

            if(valid) {
                res.push_back(word);
            }
            
        }
        return res;
    }
};
