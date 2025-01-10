class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        // Go through each word in sentence and see if it can be replaced
        // by our options in dictionary
        vector<string> sentenceArr;
        stringstream s(sentence);
        string word;
        while(s >> word) {
            sentenceArr.push_back(word);
        }

        for(int i = 0; i < sentenceArr.size(); i++) {
            string s = sentenceArr[i];
            int best = -1;
            int minSize = INT_MAX;
            
            // Go through each dictionary entry and compare it to a substring
            // of the current string s of the same length to see if we can replace it
            for(int j = 0; j < dictionary.size(); j++) {
                string possible = dictionary[j];
                string original = s.substr(0, dictionary[j].size());

                if(possible == original) {
                    // If we have found a match to replace it, we save the index of the
                    // best option (being the one of smallest length) in an integer that will
                    // be the index of the replacement in dictionary so we know what to sub
                    // for the current word in the original string
                    if(possible.size() < minSize) {
                        minSize = possible.size();
                        best = j;
                    }
                }
            }

            if(best != -1) {
                sentenceArr[i] = dictionary[best];
            }
        }

        string ans = "";
        for(int i = 0; i < sentenceArr.size(); i++) {
            ans += sentenceArr[i];
            if(i != sentenceArr.size() - 1) {
                ans += " ";
            }
        }

        return ans;
    }
};
