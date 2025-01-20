class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        // Iterate through grid and map values to corresponding rows & cols
        unordered_map<int, int> rowMap;
        unordered_map<int, int> colMap;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                rowMap[mat[i][j]] = i;
                colMap[mat[i][j]] = j;
            }
        }
        
        // Iterate through arr, incrementally add to a map of the number
        // of cells painted in each row & col. If it meets criteria, exit and
        // save the index this was found at in arr
        int minIndexRow = arr.size();
        int minIndexCol = arr.size();
        unordered_map<int, int> currRowMap;
        unordered_map<int, int> currColMap;
        for(int i = 0; i < arr.size(); i++) {
            
            currRowMap[rowMap[arr[i]]]++;
            if(currRowMap[rowMap[arr[i]]] == n) {
                minIndexRow = min(minIndexRow, i);
            }

            currColMap[colMap[arr[i]]]++;
            if(currColMap[colMap[arr[i]]] == m) {
                minIndexCol = min(minIndexCol, i);
            }
        }

        return min(minIndexRow, minIndexCol);
    }
};
