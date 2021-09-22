class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> mat;
        int r = rowSum.size();
        int c = colSum.size();
        
        for (int i=0; i<r; i++) {
            mat.push_back({});
            for (int j=0; j<c; j++) {
                int x = min(rowSum[i], colSum[j]);
                
                rowSum[i] -= x;
                colSum[j] -= x;
                
                mat[i].push_back(x);
            }
        }
        
        return mat;
    }
};