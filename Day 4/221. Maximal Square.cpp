class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<vector<int>>> memo;
        int maxx = 0;
        for (int i=0; i<matrix.size(); i++) {
            memo.push_back({});
            for (int j=0; j<matrix[i].size(); j++) {
                if (matrix[i][j] == '0') {
                    memo[i].push_back({0, 0, 0});
                }
                
                else if (i == 0 and j == 0) {
                    memo[i].push_back({1, 1, 1});
                    maxx = max(maxx, 1);
                }
                else if (i == 0) {
                    int a = 1 + memo[i][j-1][0];
                    int b = 1;
                    int c = 1;
                    
                    maxx = max(maxx, min(a, min(b, c)));
                    
                    memo[i].push_back({a, b, c});
                }
                else if (j == 0) {
                    int a = 1;
                    int b = 1;
                    int c = 1 + memo[i-1][j][2];
                    
                    maxx = max(maxx, min(a, min(b, c)));
                    
                    memo[i].push_back({a, b, c});
                }
                else {
                    int a = 1 + memo[i][j-1][0];
                    int b = 1 + memo[i-1][j-1][1];
                    int c = 1 + memo[i-1][j][2];
                    
                    b = min(a, min(b, c));
                    
                    maxx = max(maxx, b);
                    
                    memo[i].push_back({a, b, c});
                }
            }
        }
        
        
        return maxx*maxx;
    }
};