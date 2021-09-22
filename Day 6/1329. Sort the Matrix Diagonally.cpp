class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = 0;
        if (m != 0) {
            n = mat[0].size();
        }
        
        int startRow = 0;
        int startCol = n-1;
        
        while (startCol >= 0) {
            
            int i = startRow;
            int j = startCol;
            
            vector<int> vals;
            
            while (i < m and j < n) {
                vals.push_back(mat[i][j]);
                // cout << mat[i][j] << " ";
                i++;
                j++;
            }
            sort(vals.begin(), vals.end());
            
            i = startRow;
            j = startCol;
            
            while (i < m and j < n) {
                mat[i][j] = vals[i - startRow];
                i++;
                j++;
            }
            
            if (startCol == 0 and startRow < m) {
                startRow++;
            }else {
                startCol--;
            }
            
        }
        
        return mat;
    }
};