class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        
        int rowMax[n];
        int colMax[n];
        
        for (int i=0; i<n; i++) {
            rowMax[i] = -1;
            colMax[i] = -1;
        }
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                rowMax[i] = max(rowMax[i], grid[i][j]);
                colMax[j] = max(colMax[j], grid[i][j]);
            }
        }
        
        int maxIncrease = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                maxIncrease += min(rowMax[i], colMax[j]) - grid[i][j];
            }
        }
        
        return maxIncrease;
    }
};