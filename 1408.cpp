class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        for(int i = 0; i < words.size(); i++) {
            for(int j = 0; j < words.size(); j++) {
                // Have a boolean to let the traversal for the current words to
                // stop after we have found a match
                bool done = false;
                
                // Make sure we are not looking at the same words
                if(i != j) {
                    // We are testing if words[i] is a sustring of words[j]
                    // so we need to make sure its at least of length
                    if(words[j].size() >= words[i].size()) {
                        // Loop from beginning of words[j] to test all possible substrings
                        int end = words[j].size() - words[i].size() + 1;
                        for(int k = 0; k < end; k++) {
                            // Grab substring starting from current index
                            string sub = words[j].substr(k, words[i].size());
                            if(words[i] == sub) {
                                res.push_back(words[i]);
                                done = true;
                                break;
                            }
                        }
                    }
                }

                if(done) {
                    break;
                }
            }
        }

        return res;
    }
};
