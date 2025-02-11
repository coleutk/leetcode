class Solution {
public:
    int countCollisions(string directions) {
        string stk = "";
        int n = directions.size();
        int collisions = 0;
        for(char c : directions) {
            stk += c;
            while(stk.size() >= 2) {
                // Take the substring of size 2 every time
                string comp = stk.substr(stk.size() - 2);

                // Test for the different combinations: (RL, RS, SL)
                if(comp == "RL") {
                    collisions += 2;
                    // Remove this substr from the stack
                    stk.resize(stk.size() - 2);
                    // Add back an "S" to the stack for further comparisons
                    stk += 'S';
                } else if(comp == "SL" || comp == "RS") {
                    collisions += 1;
                    // Remove this substr from the stack
                    stk.resize(stk.size() - 2);
                    // Add back an "S" to the stack for further comparisons
                    stk += 'S';
                } else {
                    break;
                }
            }
        }
        return collisions;
    }
};
