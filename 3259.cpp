class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        vector<long long> dpA(n);
        vector<long long> dpB(n);
        dpA[0] = energyDrinkA[0];
        dpA[1] = energyDrinkA[1] + dpA[0];
        dpB[0] = energyDrinkB[0];
        dpB[1] = energyDrinkB[1] + dpB[0];

        for(int i = 2; i < n; i++) {
            long long choiceA = max(dpA[i - 1], dpB[i - 2]);
            dpA[i] = energyDrinkA[i] + choiceA;

            long long choiceB = max(dpB[i - 1], dpA[i - 2]);
            dpB[i] = energyDrinkB[i] + choiceB;
        } 

        return max(dpA[n - 1], dpB[n - 1]);
    }
};
