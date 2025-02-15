class Solution {
public:
    bool partition(int idx, string square, int curr, int target) {
        int n = square.size();
        if(idx == n && curr == target) {
            return true;
        }

        // We want to explore the other possibilities starting at idx
        for(int j = idx; j < n; j++) {
            // Grab the substring from the current index to the next one
            string start = square.substr(idx, j - idx + 1);

            if(partition(j + 1, square, curr + stoi(start), target)) {
                return true;
            }
        }

        return false;
    }

    int punishmentNumber(int n) {
        int res = 0;
        for(int i = 1; i <= n; i++) {
            if(partition(0, to_string(i * i), 0, i)) {
                res += i * i;
            }
        }
        return res;
    }
};
